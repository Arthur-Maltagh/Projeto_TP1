#include "ControladoraIAprPessoa.h"

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include "Nome.h"
#include "Papel.h"
#include "Senha.h"

using namespace std;

namespace {
    // Mostra a mensagem e devolve a linha digitada (aceita espacos).
    string lerLinha(const string &mensagem) {
        string linha;
        cout << mensagem;
        getline(cin, linha);
        return linha;
    }
}

// ---------------------------------------------------------------------------
// Criar conta (nao exige autenticacao)
// ---------------------------------------------------------------------------
void CntrIAprPessoa::criar() {
    cout << "\n=== Criar conta ===\n";

    // IU: pede os dados como texto.
    string txtEmail = lerLinha("Email: ");
    string txtNome  = lerLinha("Nome: ");
    string txtSenha = lerLinha("Senha: ");
    string txtPapel = lerLinha("Papel (GESTOR ou DESENVOLVEDOR): ");

    try {
        // VAL: cada set valida o formato e lanca invalid_argument se invalido.
        EMAIL email;  email.setEMAIL(txtEmail);
        Nome  nome;   nome.setNome(txtNome);
        Senha senha;  senha.setSenha(txtSenha);
        Papel papel;  papel.setPapel(txtPapel);

        Pessoa pessoa;
        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        // Chama o servico apenas pela interface.
        if (cntrISerPessoa->criar(pessoa))
            cout << "Conta criada com sucesso.\n";
        else
            cout << "Nao foi possivel criar a conta (email ja cadastrado).\n";
    }
    catch (const invalid_argument &) {
        cout << "Dado em formato invalido. Conta nao criada.\n";
    }
}

// ---------------------------------------------------------------------------
// Menu de pessoas (usuario autenticado)
// ---------------------------------------------------------------------------
void CntrIAprPessoa::executar(const EMAIL &email) {
    bool continuar = true;

    while (continuar) {
        cout << "\n=== Pessoas ===\n"
             << "1 - Ler dados de uma pessoa\n"
             << "2 - Listar pessoas\n"
             << "3 - Atualizar minha conta\n"
             << "4 - Excluir minha conta\n"
             << "0 - Voltar\n";

        string opcao = lerLinha("Opcao: ");

        if (opcao == "1")      ler();
        else if (opcao == "2") listar();
        else if (opcao == "3") atualizar(email);
        else if (opcao == "4") {
            // Se a conta foi excluida, o usuario deixa de existir: sai do menu.
            if (excluir(email)) continuar = false;
        }
        else if (opcao == "0") continuar = false;
        else cout << "Opcao invalida.\n";
    }
}

// ---------------------------------------------------------------------------
// Opcoes do menu
// ---------------------------------------------------------------------------
void CntrIAprPessoa::mostrar(Pessoa &pessoa) {
    cout << "Email: " << pessoa.getEmail().getEMAIL() << "\n"
         << "Nome:  " << pessoa.getNome().getNome() << "\n"
         << "Senha: " << pessoa.getSenha().getSenha() << "\n"
         << "Papel: " << pessoa.getPapel().getPapel() << "\n";
}

void CntrIAprPessoa::ler() {
    string txtEmail = lerLinha("Email da pessoa: ");

    try {
        EMAIL email;
        email.setEMAIL(txtEmail);

        // Na entrada, a Pessoa carrega so a chave (email).
        // Na saida, o servico preenche os demais dados.
        Pessoa pessoa;
        pessoa.setEmail(email);

        if (cntrISerPessoa->ler(&pessoa))
            mostrar(pessoa);
        else
            cout << "Pessoa nao encontrada.\n";
    }
    catch (const invalid_argument &) {
        cout << "Email em formato invalido.\n";
    }
}

void CntrIAprPessoa::listar() {
    list<EMAIL> emails;

    if (!cntrISerPessoa->listar(&emails)) {
        cout << "Nao foi possivel listar as pessoas.\n";
        return;
    }
    if (emails.empty()) {
        cout << "Nenhuma pessoa cadastrada.\n";
        return;
    }
    // Listagem mostra apenas o identificador de cada entidade.
    for (list<EMAIL>::iterator it = emails.begin(); it != emails.end(); ++it)
        cout << it->getEMAIL() << "\n";
}

void CntrIAprPessoa::atualizar(const EMAIL &email) {
    // O email identifica a pessoa e nao pode ser alterado.
    Pessoa pessoa;
    pessoa.setEmail(email);

    if (!cntrISerPessoa->ler(&pessoa)) {
        cout << "Conta nao encontrada.\n";
        return;
    }

    cout << "Dados atuais:\n";
    mostrar(pessoa);
    cout << "Informe os novos dados (o email nao pode ser alterado).\n";

    string txtNome  = lerLinha("Nome: ");
    string txtSenha = lerLinha("Senha: ");
    string txtPapel = lerLinha("Papel (GESTOR ou DESENVOLVEDOR): ");

    try {
        Nome  nome;   nome.setNome(txtNome);
        Senha senha;  senha.setSenha(txtSenha);
        Papel papel;  papel.setPapel(txtPapel);

        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        if (cntrISerPessoa->atualizar(pessoa))
            cout << "Conta atualizada com sucesso.\n";
        else
            cout << "Nao foi possivel atualizar a conta.\n";
    }
    catch (const invalid_argument &) {
        cout << "Dado em formato invalido. Conta nao atualizada.\n";
    }
}

bool CntrIAprPessoa::excluir(const EMAIL &email) {
    string confirmacao = lerLinha("Confirma a exclusao da sua conta? (S/N): ");
    if (confirmacao != "S" && confirmacao != "s") {
        cout << "Exclusao cancelada.\n";
        return false;
    }

    if (cntrISerPessoa->excluir(email)) {
        cout << "Conta excluida.\n";
        return true;
    }
    // O servico recusa a exclusao se houver projetos ou cartoes associados.
    cout << "Nao foi possivel excluir a conta (ha projetos ou cartoes associados).\n";
    return false;
}
