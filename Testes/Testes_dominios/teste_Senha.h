#ifndef TESTE_SENHA_H_INCLUDED
#define TESTE_SENHA_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../dominios/Senha.h"

using namespace std;

class Teste_Senha{
private:
    const string VALOR_VALIDO = "0nda5";
    const string VALOR_INVALIDO = "SenhaSegura";
    Senha *senha;
    int estado;
    void construtor();
    void destrutor();
    void testa_valor_valido();
    void testa_valor_invalido();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TESTE_SENHA_H_INCLUDED
