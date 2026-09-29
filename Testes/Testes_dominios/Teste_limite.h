#ifndef TESTE_LIMITE_H_INCLUDED
#define TESTE_LIMITE_H_INCLUDED

#include <stdexcept>
#include "../../dominios/Limite.h"

using namespace std;

class Teste_Limite{
private:
    static const int VALOR_VALIDO = 20;
    static const int VALOR_INVALIDO = 67;
    Limite *limite;
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

#endif // TESTE_LIMITE_H_INCLUDED
