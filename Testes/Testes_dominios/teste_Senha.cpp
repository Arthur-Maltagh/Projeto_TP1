#include <iostream>
#include <stdexcept>
#include "../../dominios/Senha.h"
#include "teste_Senha.h"

using namespace std;

void Teste_Senha::construtor(){
    senha = new Senha();
    estado = SUCESSO;
}

void Teste_Senha::destrutor(){
    delete senha;
}

void Teste_Senha::testa_valor_valido(){
    try{
        senha->setSenha(VALOR_VALIDO);
        if(senha->getSenha() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_Senha::testa_valor_invalido(){
     try{
        senha->setSenha(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(senha->getSenha() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_Senha::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}
