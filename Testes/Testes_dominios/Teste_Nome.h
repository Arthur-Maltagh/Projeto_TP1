#ifndef TESTE_NOME_H_INCLUDED
#define TESTE_NOME_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../dominios/Nome.h"

using namespace std;

class Teste_Nome{
private:
    const string VALOR_VALIDO = "Donald biden";
    const string VALOR_INVALIDO = "  Jorge Lafont dos santos";
    Nome *nome;
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

#endif // TESTE_NOME_H_INCLUDED

/*
Texto com até 15 caracteres. Caractere pode ser letra maiúscula (A-Z), letra minúscula (a-z) ou espaço em branco;
espaço em branco é seguido por letra; primeiro caractere não é espaço em branco; último caractere não é espaço em branco.*/
