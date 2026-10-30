#ifndef TESTE_TIMESTAMP_H_INCLUDED
#define TESTE_TIMESTAMP_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../dominios/Timestamp.h"

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

/*DIA-MÊS-ANO-HORÁRIO
DIA é número 1 a 31.
MÊS é sigla JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
ANO é número de 2000 a 2099.
HORÁRIO é valor de 00:00 a 23:59
A data deve ser válida considerando anos bissextos.*/
