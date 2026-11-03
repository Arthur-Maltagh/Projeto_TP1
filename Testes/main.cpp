#include <iostream>
#include <string>
#include "Teste_limite.h"
#include "teste_Senha.h"
#include "Teste_Nome.h"
#include "Teste_Texto.h"
#include "Teste_Identificador.h"
#include "Teste_EMAIL.h"
#include "Teste_Estado.h"
#include "Teste_Papel.h"
#include "Teste_Prioridade.h"
#include "Teste_Tamanho.h"
#include "Teste_Timestamp.h"

#include "Teste_entidades/Teste_Pessoa.h"
#include "Teste_Projeto.h"
#include "Teste_Quadro.h"
#include "Teste_Cartaoatividade.h"

#include "DriverAutenticacao.h"
#include "DriverPessoa.h"
#include "DriverAutenticacao.h"
#include "DriverMaic.h"

using namespace std;

// Mostra o resultado de um teste. Cada run() devolve 0 quando aprovado.
static void mostrarResultado(const string &descricao, int resultado) {
    if(resultado == 0){
        cout << "Teste " << descricao << ": Aprovado!" << endl;
    }else{
         cout << "Teste " << descricao << ": Falhou!" << endl;
    }

}

static void executarTestesDominios() {
    Teste_Limite limite;
    Teste_Senha senha;
    Teste_Nome nome;
    Teste_Texto texto;
    Teste_Identificador identificador;
    Teste_EMAIL email;
    Teste_Estado estado;
    Teste_Prioridade prioridade;
    Teste_Papel papel;
    Teste_Tamanho tamanho;
    Teste_Timestamp timestamp;

    cout << "\n--- Testes dos dominios ---\n";
    mostrarResultado("do Dominio Limite", limite.run());
    mostrarResultado("do Dominio Nome", nome.run());
    mostrarResultado("do Dominio Senha", senha.run());
    mostrarResultado("do Dominio Texto", texto.run());
    mostrarResultado("do Dominio Identificador", identificador.run());
    mostrarResultado("do Dominio EMAIL", email.run());
    mostrarResultado("do Dominio Estado", estado.run());
    mostrarResultado("do Dominio Papel", papel.run());
    mostrarResultado("do Dominio Prioridade", prioridade.run());
    mostrarResultado("do Dominio Tamanho", tamanho.run());
    mostrarResultado("do Dominio Timestamp", timestamp.run());
}

static void executarTestesEntidades() {
    Teste_Pessoa pessoa;
    Teste_Projeto projeto;
    Teste_Quadro quadro;
    Teste_CartaoDeAtividade cartaodeatividade;

    cout << "\n--- Testes das entidades ---\n";
    mostrarResultado("da Entidade Pessoa", pessoa.run());
    mostrarResultado("da Entidade Quadro", quadro.run());
    mostrarResultado("da Entidade Projeto", projeto.run());
    mostrarResultado("da Entidade Cartao de Atividade", cartaodeatividade.run());
}



 static char lerOpcao(const string &mensagem) {
    string linha;
    cout << mensagem;
    getline(cin, linha);
    if(linha.length() == 1 && isdigit(linha[0])){
        return linha[0];
    }else{
        return '?';
    }
}

int main() {
    bool continuar = true;

    while (continuar) {
        cout << "\n=== TESTES ===\n"
             << "1 - Testes dos dominios e das entidades\n"
             << "2 - Teste do servico de autenticacao\n"
             << "3 - Driver da apresentacao de pessoas\n"
             << "4 - Driver da apresentacao de autenticacao\n"
             << "5 - Driver do MAIC (autenticacao e pessoas reais)\n"
             << "0 - Sair\n";

         char opcao = lerOpcao("Opcao: ");

        switch (opcao) {
            case '1':
                executarTestesDominios();
                executarTestesEntidades();
                break;
            case '2':
                executarTesteServicoAutenticacao();
                break;
            case '3':
                executarDriverPessoa();
                break;
            case '4':
                executarDriverAutenticacao();
                break;
            case '5':
                executarDriverMAIC();
                break;
            case '0':
                continuar = false;
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }

    cout << "\nPressione ENTER para sair...";
    cin.get();

    return 0;
}
