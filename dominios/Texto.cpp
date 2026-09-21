#include "Texto.h"
#include <stdexcept>
#include <cctype>
using namespace std;

bool Texto::validar(string texto){
    if(texto.empty())
        return false;

    if(texto.length() > TAMANHO_MAX)
        return false;

    if(!isupper(texto[0]) || texto[texto.length() - 1] != '.')
        return false;

    for(int i = 0;i < texto.length() - 1;i++){
        if(!isalnum(texto[i])){
            if(texto[i] != ',' && texto[i] != ';' && texto[i] != '.' && texto[i] != ':' && texto[i] != '?' && texto[i] != '!' && texto[i] != ' '){
                return false;
            }else{
                if(texto[i + 1] == ',' || texto[i + 1] == ';' || texto[i + 1] == '.' || texto[i + 1] == ':' || texto[i + 1] == '?' || texto[i + 1] == '!' || texto[i + 1] == ' ')
                    return false;
            }
        }
    }
    return true;
}

void Texto::setTexto(string texto){
    if(!validar(texto))
        throw invalid_argument("Argumento invalido");
    this -> texto = texto;
}

string Texto::getTexto(){
    return texto;
}



/*
Texto com até 30 caracteres.
Caractere pode ser letra (a-z ou A-Z), dígito (0-9), espaço em branco ou sinal de pontuação
(vírgula, ponto-e-vírgula, ponto, dois pontos, ponto de interrogação, ponto de exclamação); sinal de
pontuação não é seguido por sinal de pontuação; primeiro caractere é letra maiúscula; último
caractere é ponto.
*/
