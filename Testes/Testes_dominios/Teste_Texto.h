#ifndef TESTE_TEXTO_H_INCLUDED
#define TESTE_TEXTO_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../dominios/Texto.h"

using namespace std;

class Teste_Texto{
private:
    const string VALOR_VALIDO = "So sei que nada sei.";
    const string VALOR_INVALIDO = "SABO DE TUDO,, E MAS UM Poco!!";
    Texto *texto;
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

#endif // TESTE_TEXTO_H_INCLUDED
