#include <iostream>
#include <stdexcept>
#include "../../dominios/Nome.h"
#include "Teste_Nome.h"

using namespace std;

void Teste_Nome::construtor(){
    nome = new Nome();
    estado = SUCESSO;
}

void Teste_Nome::destrutor(){
    delete nome;
}

void Teste_Nome::testa_valor_valido(){
    try{
        nome->setNome(VALOR_VALIDO);
        if(nome->getNome() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(invalid_argument &excecao){
        estado = FALHA;
    }

}

void Teste_Nome::testa_valor_invalido(){
     try{
        nome->setNome(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument &excecao){
        if(nome->getNome() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int Teste_Nome::run(){
    construtor();
    testa_valor_valido();
    testa_valor_invalido();
    destrutor();
    return estado;
}
