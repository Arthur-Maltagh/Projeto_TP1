#ifndef TESTE_IDENTIFICADOR_H_INCLUDED
#define TESTE_IDENTIFICADOR_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../dominios/Identificador.h"

using namespace std;


class Teste_Identificador{
private:
    const string VALOR_VALIDO = "Fla777";
    const string VALOR_INVALIDO = "666Flu";
    Identificador *identificador;
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

#endif // TESTE_IDENTIFICADOR_H_INCLUDED
