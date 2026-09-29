#include <iostream>
#include <stdexcept>
#include "../../dominios/Limite.h"
#include "Teste_limite.h"

using namespace std;

void Teste_Limite::construtor(){
    limite = new Limite();
    estado = SUCESSO;
}

void Teste_Limite::destrutor(){
    delete limite;
}

void Teste_Limite::testa_valor_valido(){
    try{
        limite->setLimite(VALOR_VALIDO);
        if(limite->getLimite() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_Limite::testa_valor_invalido(){
     try{
        limite->setLimite(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(limite->getLimite() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_Limite::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}













