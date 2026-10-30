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

    for(size_t i = 0;i < texto.length() - 1;i++){
        if(!isalnum(texto[i])){
            if(texto[i] != ',' && texto[i] != ';' && texto[i] != '.' && texto[i] != ':' && texto[i] != '?' && texto[i] != '!' &&  texto[i] != ' '){
                return false;
            }else{
                if(texto[i + 1] == ',' || texto[i + 1] == ';' || texto[i + 1] == '.' || texto[i + 1] == ':' || texto[i + 1] == '?' || texto[i + 1] == '!')
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

