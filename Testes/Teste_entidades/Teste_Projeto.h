#ifndef TESTE_PROJETO_H_INCLUDED
#define TESTE_PROJETO_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../entidades/projeto.h"

#include "../../dominios/Identificador.h"
#include "../../dominios/nome.h"
#include "../../dominios/Texto.h"
#include "../../dominios/Timestamp.h"

using namespace std;

class Teste_Projeto {
private:
    const string VALOR_IDENTIFICADOR = "USP867";
    const string VALOR_NOME = "slavei";
    const string VALOR_DESCRICAO = "Desenvolvimento web.";
    const string VALOR_TIMESTAMP = "01-AGO-2007-04:44";

    Projeto *projeto;
    int estado;

    void construtor();
    void destrutor();
    void testa_valor_valido();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


#endif // TESTE_PROJETO_H_INCLUDED
