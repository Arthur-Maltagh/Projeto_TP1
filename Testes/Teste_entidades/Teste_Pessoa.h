#ifndef TESTE_PESSOA_H_INCLUDED
#define TESTE_PESSOA_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../entidades/pessoa.h"

using namespace std;

class Teste_Pessoa{
private:
    const string VALOR_EMAIL = "shaolin-matador@de.porco.com";
    const string VALOR_NOME = "Shaolin Porco";
    const string VALOR_SENHA = "S609P";

    Pessoa *pessoa;
    int estado;

    void construtor();
    void destrutor();
    void testa_valor_valido();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};

#endif // TESTE_PESSOA_H_INCLUDED
