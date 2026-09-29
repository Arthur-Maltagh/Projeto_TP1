#include <iostream>
#include <stdexcept>
#include "../../dominios/EMAIL.h"
#include "Teste_EMAIL.h"

using namespace std;

void Teste_EMAIL::construtor(){
    Email = new EMAIL();
    estado = SUCESSO;
}

void Teste_EMAIL::destrutor(){
    delete Email;
}

void Teste_EMAIL::testa_valor_valido(){
    try{
        Email->setEMAIL(VALOR_VALIDO);
        if(Email->getEMAIL() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_EMAIL::testa_valor_invalido(){
     try{
        Email->setEMAIL(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(Email->getEMAIL() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_EMAIL::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}
