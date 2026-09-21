#include "Senha.h"
#include <stdexcept>
#include <cctype>
using namespace std;

bool Senha::validar(string senha){
    if(senha.length() != TAMANHO_SENHA)
        return false;
    bool tem_letra = false;
    bool tem_numero = false;
    for(int i = 0; i < TAMANHO_SENHA;i++){
        if(!isalnum(senha[i]))
            return false;
        if(isalpha(senha[i])){
            tem_letra = true;
        }else{
            tem_numero = true;
        }
    }
    if(!tem_letra || !tem_numero)
        return false;

    return true;
}

void Senha::setSenha(string senha){
    if(!validar(senha))
        throw invalid_argument("Argumento invalido");
    this -> senha = senha;
}

string Senha::getSenha(){
    return senha;
}

