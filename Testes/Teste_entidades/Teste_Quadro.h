#ifndef TESTE_QUADRO_H_INCLUDED
#define TESTE_QUADRO_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../entidades/quadro.h"

#include "../../dominios/Identificador.h"
#include "../../dominios/nome.h"
#include "../../dominios/Limite.h"

using namespace std;

class Teste_Quadro {
private:
    const string VALOR_IDENTIFICADOR = "UNB786";
    const string VALOR_NOME = "quadro";
    const int VALOR_LIMITE = 5;

    Quadro *quadro;
    int estado;

    void construtor();
    void destrutor();
    void testa_valor_valido();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};

#endif // TESTE_QUADRO_H_INCLUDED
