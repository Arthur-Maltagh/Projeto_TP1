#include <iostream>
#include <stdexcept>
#include "../../dominios/Identificador.h"
#include "Teste_Identificador.h"

using namespace std;

void Teste_Identificador::construtor(){
    identificador = new Identificador();
    estado = SUCESSO;
}

void Teste_Identificador::destrutor(){
    delete identificador;
}

void Teste_Identificador::testa_valor_valido(){
    try{
        identificador->setIdentificador(VALOR_VALIDO);
        if(identificador->getIdentificador() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_Identificador::testa_valor_invalido(){
     try{
        identificador->setIdentificador(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(identificador->getIdentificador() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_Identificador::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}
