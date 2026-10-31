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

#include "DriverCntrIAprPessoa.h"

using namespace std;

// Mostra o resultado de um teste. Cada run() devolve 0 quando aprovado.
static void mostrarResultado(const string &descricao, int resultado) {
    cout << "Teste " << descricao << ": "
         << (resultado == 0 ? "Aprovado!" : "Falhou!") << endl;
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

int main() {
    bool continuar = true;

    while (continuar) {
        cout << "\n=== TESTES ===\n"
             << "1 - Testes dos dominios\n"
             << "2 - Testes das entidades\n"
             << "3 - Testes dos dominios e das entidades\n"
             << "4 - Driver da apresentacao de pessoas\n"
             << "0 - Sair\n"
             << "Opcao: ";

        string opcao;
        getline(cin, opcao);

        if (opcao == "1") {
            executarTestesDominios();
        }
        else if (opcao == "2") {
            executarTestesEntidades();
        }
        else if (opcao == "3") {
            executarTestesDominios();
            executarTestesEntidades();
        }
        else if (opcao == "4") {
            executarDriverPessoa();
        }
        else if (opcao == "0") {
            continuar = false;
        }
        else {
            cout << "Opcao invalida.\n";
        }
    }

    cout << "\nPressione ENTER para sair...";
    cin.get();

    return 0;
}
