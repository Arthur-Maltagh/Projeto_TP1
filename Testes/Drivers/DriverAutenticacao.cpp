#include "DriverAutenticacao.h"

#include <iostream>
#include <string>
#include "ControladoraIAprAutenticacao.h"
#include "ControladoraISerAutenticacao.h"
#include "EMAIL.h"
#include "Nome.h"
#include "Papel.h"
#include "Pessoa.h"
#include "Senha.h"
#include "StubSerAutenticacao.h"
#include "StubISerPessoa.h"

using namespace std;

// ---------------------------------------------------------------------------
// Driver interativo da apresentacao (servico substituido por stub)
// ---------------------------------------------------------------------------
int executarDriverAutenticacao() {
    StubISerAutenticacao stub;
    CntrIAprAutenticacao controladora;
    controladora.setCntrISerAutenticacao(&stub);

    cout << "Credencial aceita pelo stub: ana@teste.com / abc12\n";

    bool continuar = true;
    while (continuar) {
        cout << "\n=== DRIVER MAAU ===\n"
             << "1 - Autenticar\n"
             << "0 - Voltar\n"
             << "Opcao: ";

        string opcao;
        getline(cin, opcao);

        if (opcao == "1") {
            EMAIL email;
            if (controladora.autenticar(&email))
                cout << "Usuario autenticado: " << email.getEMAIL() << "\n";
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

// ---------------------------------------------------------------------------
// Teste automatico do servico (servico de pessoas substituido por stub)
// ---------------------------------------------------------------------------
namespace {
    EMAIL fazerEmail(const string &txt) {
        EMAIL e;  e.setEMAIL(txt);  return e;
    }
    Senha fazerSenha(const string &txt) {
        Senha s;  s.setSenha(txt);  return s;
    }

    // Retorna 0 se o resultado obtido e o esperado.
    int verificar(const string &caso, bool obtido, bool esperado) {
        bool aprovado = (obtido == esperado);
        cout << "  " << caso << ": " << (aprovado ? "Aprovado!" : "Falhou!") << endl;
        return aprovado ? 0 : 1;
    }
}

int executarTesteServicoAutenticacao() {
    StubISerPessoa pessoas;
    CntrISerAutenticacao servico;
    servico.setCntrISerPessoa(&pessoas);

    // Prepara uma conta cadastrada.
    Pessoa ana;
    ana.setEmail(fazerEmail("ana@teste.com"));
    Nome nome;   nome.setNome("Ana");
    Senha senha; senha.setSenha("abc12");
    Papel papel; papel.setPapel("GESTOR");
    ana.setNome(nome);
    ana.setSenha(senha);
    ana.setPapel(papel);
    pessoas.criar(ana);

    cout << "\n--- Teste do servico de autenticacao ---\n";
    int falhas = 0;
    falhas += verificar("credenciais corretas",
                        servico.autenticar(fazerEmail("ana@teste.com"), fazerSenha("abc12")), true);
    falhas += verificar("senha incorreta",
                        servico.autenticar(fazerEmail("ana@teste.com"), fazerSenha("zzz99")), false);
    falhas += verificar("email nao cadastrado",
                        servico.autenticar(fazerEmail("bia@teste.com"), fazerSenha("abc12")), false);

    cout << "Teste do servico de autenticacao: "
         << (falhas == 0 ? "Aprovado!" : "Falhou!") << endl;
    return falhas;
}
