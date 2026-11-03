#include "ControladoraIAprPrincipal.h"

#include <iostream>
#include <string>

using namespace std;


    // Mostra a mensagem e devolve a linha digitada.
static string lerLinha(const string &mensagem) {
    string linha;
    cout << mensagem;
    getline(cin, linha);
    return linha;
}

static char lerOpcao(const string &mensagem) {
    string linha = lerLinha(mensagem);
    if(linha.length() == 1 && isdigit(linha[0])){
        return linha[0];
    }else{
        return '?';
    }
}

void CntrIAprPrincipal::executar() {
    bool continuar = true;

    while (continuar) {
        cout << "\n=== SISTEMA KANBAN ===\n"
             << "1 - Entrar\n"
             << "2 - Criar conta\n"
             << "0 - Encerrar\n";
        char opcao = lerOpcao("Opcao: ");

        switch (opcao) {
            case '1': {
                EMAIL email;
            // O modulo de autenticacao pede os dados, valida o formato e
            // informa o motivo quando a autenticacao falha.
                if (cntrIAprAutenticacao->autenticar(&email))
                    executarSessao(email);
                    break;
            }
            case '2':
                cntrIAprPessoa->criar();
                break;
            case '0':
                continuar = false;
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }
}

void CntrIAprPrincipal::executarSessao(const EMAIL &email) {
    bool autenticado = true;

    while (autenticado) {
        cout << "\n=== MENU PRINCIPAL ===\n"
             << "1 - Pessoas\n"
             << "2 - Projetos, quadros e cartoes\n"
             << "0 - Sair da conta\n";

          char opcao = lerOpcao("Opcao: ");

        // O papel do usuario (gestor ou desenvolvedor) e tratado dentro de
        // cada modulo, que oferece apenas os servicos permitidos.
        switch (opcao) {
            case '1':
                cntrIAprPessoa->executar(email);
                break;
            case '2':
                cntrIAprProjeto->executar(email);
                break;
            case '0':
                autenticado = false;
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }
}
