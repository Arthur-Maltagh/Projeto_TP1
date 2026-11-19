#include "ControladoraIAprProjeto.h"

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "Identificador.h"
#include "nome.h"
#include "Texto.h"
#include "Timestamp.h"
#include "Pessoa.h"
#include "Papel.h"

using namespace std;

static string lerLinha(const string &mensagem) {
    string linha;
    cout << mensagem;
    getline(cin, linha);
    return linha;
}

static bool lerIdentificador(const string &mensagem, Identificador *identificador) {
    try {
        identificador->setIdentificador(lerLinha(mensagem));
        return true;
    }
    catch (const invalid_argument &) {
        cout << "Identificador invalido. Use tres letras seguidas de tres digitos.\n";
        return false;
    }
}

static bool confirmar(const string &mensagem) {
    while (true) {
        string resposta = lerLinha(mensagem);
        if (resposta == "S" || resposta == "s")
            return true;
        if (resposta == "N" || resposta == "n")
            return false;
        cout << "Resposta invalida. Digite S ou N.\n";
    }
}

void CntrIAprProjeto::mostrarProjeto(Projeto &projeto) {
    Identificador identificador = projeto.getIdentificador();
    Nome nome = projeto.getNome();
    Texto descricao = projeto.getDescricao();
    Timestamp inicio = projeto.getInicio();
    Timestamp termino = projeto.getTermino();

    cout << "Identificador: " << identificador.getIdentificador() << "\n"
         << "Nome: " << nome.getNome() << "\n"
         << "Descricao: " << descricao.getTexto() << "\n"
         << "Inicio: " << inicio.getTimestamp() << "\n"
         << "Termino: " << termino.getTimestamp() << "\n";
}

void CntrIAprProjeto::criarProjeto(const EMAIL &gestor) {
    Projeto projeto;
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

    try {
        identificador.setIdentificador(lerLinha("Identificador (ABC123): "));
        nome.setNome(lerLinha("Nome (ate 15 caracteres): "));
        descricao.setTexto(lerLinha("Descricao (ate 30 caracteres, iniciada por maiuscula e terminada em ponto): "));
        inicio.setTimestamp(lerLinha("Inicio (DIA-MES-ANO-HH:MM): "));
        termino.setTimestamp(lerLinha("Termino (DIA-MES-ANO-HH:MM): "));

        projeto.setIdentificador(identificador);
        projeto.setNome(nome);
        projeto.setDescricao(descricao);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
    }
    catch (const invalid_argument &) {
        cout << "Dado em formato invalido. Projeto nao cadastrado.\n";
        return;
    }

    if (cntrISerProjeto->criar(projeto, gestor))
        cout << "Projeto criado com sucesso.\n";
    else
        cout << "Nao foi possivel criar o projeto. Verifique se o identificador ja existe.\n";
}

void CntrIAprProjeto::lerProjeto() {
    Identificador identificador;
    if (!lerIdentificador("Identificador do projeto: ", &identificador))
        return;

    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (cntrISerProjeto->ler(&projeto))
        mostrarProjeto(projeto);
    else
        cout << "Projeto nao encontrado.\n";
}

void CntrIAprProjeto::atualizarProjeto() {
    Identificador identificador;
    if (!lerIdentificador("Identificador do projeto a atualizar: ", &identificador))
        return;

    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!cntrISerProjeto->ler(&projeto)) {
        cout << "Projeto nao encontrado.\n";
        return;
    }

    cout << "Dados atuais:\n";
    mostrarProjeto(projeto);
    cout << "Informe os novos dados. O identificador nao pode ser alterado.\n";

    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
    try {
        nome.setNome(lerLinha("Novo nome: "));
        descricao.setTexto(lerLinha("Nova descricao: "));
        inicio.setTimestamp(lerLinha("Novo inicio (DIA-MES-ANO-HH:MM): "));
        termino.setTimestamp(lerLinha("Novo termino (DIA-MES-ANO-HH:MM): "));

        projeto.setNome(nome);
        projeto.setDescricao(descricao);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
    }
    catch (const invalid_argument &) {
        cout << "Dado em formato invalido. Projeto nao atualizado.\n";
        return;
    }

    if (cntrISerProjeto->atualizar(projeto))
        cout << "Projeto atualizado com sucesso.\n";
    else
        cout << "Nao foi possivel atualizar o projeto.\n";
}

void CntrIAprProjeto::excluirProjeto() {
    Identificador identificador;
    if (!lerIdentificador("Identificador do projeto a excluir: ", &identificador))
        return;

    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!cntrISerProjeto->ler(&projeto)) {
        cout << "Projeto nao encontrado.\n";
        return;
    }

    unsigned int quantidadeQuadros = 0;
    if (!cntrISerProjeto->contarQuadros(identificador, &quantidadeQuadros)) {
        cout << "Nao foi possivel verificar as dependencias do projeto. "
             << "A exclusao foi cancelada.\n";
        return;
    }

    if (quantidadeQuadros > 0) {
        Identificador copia = identificador;
        cout << "Voce nao pode excluir o projeto "
             << copia.getIdentificador() << " pois ha "
             << quantidadeQuadros
             << (quantidadeQuadros == 1 ? " quadro nele. " : " quadros nele. ")
             << (quantidadeQuadros == 1 ? "Exclua o quadro primeiro.\n"
                                        : "Exclua os quadros primeiro.\n");
        return;
    }

    if (!confirmar("O projeto nao possui quadros. Confirma a exclusao? (S/N): ")) {
        cout << "Operacao cancelada.\n";
        return;
    }

    if (cntrISerProjeto->excluir(identificador))
        cout << "Projeto excluido com sucesso.\n";
    else
        cout << "Nao foi possivel excluir o projeto. Verifique novamente suas dependencias.\n";
}

void CntrIAprProjeto::listarProjetos() {
    list<Identificador> identificadores;
    if (!cntrISerProjeto->listar(&identificadores)) {
        cout << "Nao foi possivel listar os projetos.\n";
        return;
    }

    if (identificadores.empty()) {
        cout << "Nenhum projeto cadastrado.\n";
        return;
    }

    for (list<Identificador>::iterator it = identificadores.begin();
         it != identificadores.end(); ++it) {
        Identificador identificador = *it;
        cout << identificador.getIdentificador() << "\n";
    }
}

void CntrIAprProjeto::abrirQuadros(const EMAIL &usuario) {
    if (cntrIAprQuadro == nullptr) {
        cout << "Modulo de quadros ainda nao esta conectado.\n";
        return;
    }

    Identificador identificador;
    if (!lerIdentificador("Identificador do projeto: ", &identificador))
        return;

    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!cntrISerProjeto->ler(&projeto)) {
        cout << "Projeto nao encontrado.\n";
        return;
    }

    cntrIAprQuadro->executar(usuario, identificador);
}

void CntrIAprProjeto::executar(const EMAIL &email) {
    if (cntrISerProjeto == nullptr || cntrISerPessoa == nullptr) {
        cout << "Modulo de projetos nao configurado corretamente.\n";
        return;
    }

    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!cntrISerPessoa->ler(&pessoa)) {
        cout << "Usuario autenticado nao encontrado.\n";
        return;
    }

    Papel papel = pessoa.getPapel();
    const bool ehGestor = papel.getPapel() == "GESTOR";
    bool continuar = true;

    while (continuar) {
        cout << "\n=== PROJETOS ===\n";
        if (ehGestor) {
            cout << "1 - Criar projeto\n"
                 << "2 - Ler projeto\n"
                 << "3 - Atualizar projeto\n"
                 << "4 - Excluir projeto\n"
                 << "5 - Listar projetos\n"
                 << "6 - Acessar quadros de um projeto\n"
                 << "0 - Voltar\n";
            string opcao = lerLinha("Opcao: ");
            if (opcao == "1") criarProjeto(email);
            else if (opcao == "2") lerProjeto();
            else if (opcao == "3") atualizarProjeto();
            else if (opcao == "4") excluirProjeto();
            else if (opcao == "5") listarProjetos();
            else if (opcao == "6") abrirQuadros(email);
            else if (opcao == "0") continuar = false;
            else cout << "Opcao invalida.\n";
        }
        else {
            cout << "1 - Ler projeto\n"
                 << "2 - Listar projetos\n"
                 << "3 - Acessar quadros de um projeto\n"
                 << "0 - Voltar\n";
            string opcao = lerLinha("Opcao: ");
            if (opcao == "1") lerProjeto();
            else if (opcao == "2") listarProjetos();
            else if (opcao == "3") abrirQuadros(email);
            else if (opcao == "0") continuar = false;
            else cout << "Opcao invalida.\n";
        }
    }
}
