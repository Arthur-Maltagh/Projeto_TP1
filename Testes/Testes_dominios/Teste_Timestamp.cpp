#include <iostream>
#include <stdexcept>
#include "../../dominios/Timestamp.h"
#include "Teste_Timestamp.h"

using namespace std;

void Teste_Timestamp::construtor(){
    timestamp = new Timestamp();
    estado = SUCESSO;
}

void Teste_Timestamp::destrutor(){
    delete timestamp;
}

void Teste_Timestamp::testa_valor_valido(){
    try{
        timestamp->setTimestamp(VALOR_VALIDO);
        if(timestamp->getTimestamp() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_Timestamp::testa_valor_invalido(){
     try{
        timestamp->setTimestamp(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(timestamp->getTimestamp() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_Timestamp::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}
