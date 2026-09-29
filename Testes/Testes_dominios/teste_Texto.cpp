#include <iostream>
#include <stdexcept>
#include "../../dominios/Texto.h"
#include "Teste_Texto.h"

using namespace std;

void Teste_Texto::construtor(){
    texto = new Texto();
    estado = SUCESSO;
}

void Teste_Texto::destrutor(){
    delete texto;
}

void Teste_Texto::testa_valor_valido(){
    try{
        texto->setTexto(VALOR_VALIDO);
        if(texto->getTexto() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_Texto::testa_valor_invalido(){
     try{
        texto->setTexto(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(texto->getTexto() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_Texto::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}
