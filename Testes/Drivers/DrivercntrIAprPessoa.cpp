/**
 * @file DriverCntrIAprPessoa.cpp
 * @brief Driver para testar a controladora de apresentacao de pessoas.
 *
 * Liga CntrIAprPessoa a um stub de ISerPessoa e permite exercitar o
 * menu pelo console. A funcao executarDriverPessoa() e chamada pelo main
 * dos testes (main.cpp da pasta de testes).
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include "ControladoraIAprPessoa.h"
#include "DriverCntrIAprPessoa.h"
#include "EMAIL.h"
#include "Nome.h"
#include "Papel.h"
#include "Pessoa.h"
#include "Senha.h"
#include "StubISerPessoa.h"

using namespace std;

// Cadastra uma conta inicial para o teste poder entrar direto no menu.
static void semear(ISerPessoa *servico) {
    EMAIL email;  email.setEMAIL("ana@teste.com");
    Nome  nome;   nome.setNome("Ana");
    Senha senha;  senha.setSenha("abc12");
    Papel papel;  papel.setPapel("GESTOR");

    Pessoa pessoa;
    pessoa.setEmail(email);
    pessoa.setNome(nome);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);

    servico->criar(pessoa);
}

int executarDriverPessoa() {
    StubISerPessoa stub;            // servico falso
    CntrIAprPessoa controladora;    // modulo testado
    controladora.setCntrISerPessoa(&stub);

    semear(&stub);
    cout << "Conta inicial: ana@teste.com / senha abc12 (GESTOR)\n";

    bool continuar = true;
    while (continuar) {
        cout << "\n=== DRIVER MAPE ===\n"
             << "1 - Criar conta\n"
             << "2 - Menu de pessoas (simula usuario autenticado)\n"
             << "0 - Sair\n"
             << "Opcao: ";

        string opcao;
        getline(cin, opcao);

        if (opcao == "1") {
            controladora.criar();
        }
        else if (opcao == "2") {
            cout << "Email do usuario autenticado: ";
            string txt;
            getline(cin, txt);

            try {
                EMAIL email;
                email.setEMAIL(txt);

                Pessoa pessoa;
                pessoa.setEmail(email);
                if (stub.ler(&pessoa))
                    controladora.executar(email);
                else
                    cout << "Usuario nao cadastrado.\n";
            }
            catch (const invalid_argument &) {
                cout << "Email em formato invalido.\n";
            }
        }
        else if (opcao == "0") {
            continuar = false;
        }
        else {
            cout << "Opcao invalida.\n";
        }
    }
    return 0;
}
