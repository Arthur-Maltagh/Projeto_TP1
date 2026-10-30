#ifndef TESTE_CARTAOATIVIDADE_H_INCLUDED
#define TESTE_CARTAOATIVIDADE_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../entidades/CartaoAtividades.h"


#include "../../dominios/Identificador.h"
#include "../../dominios/nome.h"
#include "../../dominios/Texto.h"
#include "../../dominios/Prioridade.h"
#include "../../dominios/Estado.h"
#include "../../dominios/Tamanho.h"
#include "../../dominios/Timestamp.h"

using namespace std;

class Teste_CartaoDeAtividade {
private:
    const string VALOR_IDENTIFICADOR = "ABC123";
    const string VALOR_NOME = "junin";
    const string VALOR_DESCRICAO = "Texto.";
    const string VALOR_PRIORIDADE = "ALTA";
    const string VALOR_ESTADO = "FEITO";
    const string VALOR_TAMANHO = "GRANDE";
    const string VALOR_TIMESTAMP = "15-JAN-2077-20:18";

    CartaoDeAtividade *cartao;
    int estado;

    void construtor();
    void destrutor();
    void testa_valor_valido();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};

#endif // TESTE_CARTAOATIVIDADE_H_INCLUDED
