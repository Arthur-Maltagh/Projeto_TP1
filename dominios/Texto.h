#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED
#include <string>
using namespace std;

class Texto{
private:
    string texto;
    bool validar(string texto);
    static const int TAMANHO_MAX = 30;
public:
    void setTexto(string texto);
    string getTexto();
};

#endif // TEXTO_H_INCLUDED


/*
Texto com até 30 caracteres.
Caractere pode ser letra (a-z ou A-Z), dígito (0-9), espaço em branco ou sinal de pontuação
(vírgula, ponto-e-vírgula, ponto, dois pontos, ponto de interrogação, ponto de exclamação); sinal de
pontuação não é seguido por sinal de pontuação; primeiro caractere é letra maiúscula; último
caractere é ponto.
*/
