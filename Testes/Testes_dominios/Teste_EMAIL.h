#ifndef TESTE_EMAIL_H_INCLUDED
#define TESTE_EMAIL_H_INCLUDED

#include <stdexcept>
#include <string>
#include "../../dominios/EMAIL.h"

using namespace std;


class Teste_EMAIL{
private:
    const string VALOR_VALIDO = "manoel-70-gomes@caneta-30-azul.com.br";
    const string VALOR_INVALIDO = "Rodrigo09@-faro1.1.com";
    EMAIL *Email;
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

#endif // TESTE_EMAIL_H_INCLUDED
