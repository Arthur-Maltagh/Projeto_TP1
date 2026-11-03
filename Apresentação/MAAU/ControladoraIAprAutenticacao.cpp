#include "ControladoraIAprAutenticacao.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include "Senha.h"

using namespace std;

namespace {
    // Mostra a mensagem e devolve a linha digitada.
    string lerLinha(const string &mensagem) {
        string linha;
        cout << mensagem;
        getline(cin, linha);
        return linha;
    }
}

bool CntrIAprAutenticacao::autenticar(EMAIL *email) {
    cout << "\n=== Entrar ===\n";

    // IU: pede os dados como texto.
    string txtEmail = lerLinha("Email: ");
    string txtSenha = lerLinha("Senha: ");

    try {
        // VAL: cada set valida o formato e lanca invalid_argument se invalido.
        EMAIL emailDigitado;  emailDigitado.setEMAIL(txtEmail);
        Senha senhaDigitada;  senhaDigitada.setSenha(txtSenha);

        // Consulta o servico apenas pela interface.
        if (cntrISerAutenticacao->autenticar(emailDigitado, senhaDigitada)) {
            *email = emailDigitado;
            cout << "Autenticado com sucesso.\n";
            return true;
        }
        cout << "Email ou senha incorretos.\n";
        return false;
    }
    catch (const invalid_argument &) {
        cout << "Email ou senha em formato invalido.\n";
        return false;
    }
}
