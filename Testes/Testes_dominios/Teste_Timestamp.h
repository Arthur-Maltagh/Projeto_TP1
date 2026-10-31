#ifndef TESTE_TIMESTAMP_H_INCLUDED
#define TESTE_TIMESTAMP_H_INCLUDED

#include <stdexcept>
#include <string>
#include "Timestamp.h"

using namespace std;


class Teste_Timestamp{
private:
    const string VALOR_VALIDO = "7-SET-2022-13:22";
    const string VALOR_INVALIDO = "30-FEV-2077-03:00";
    Timestamp *timestamp;
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

#endif // TESTE_TIMESTAMP_H_INCLUDED
