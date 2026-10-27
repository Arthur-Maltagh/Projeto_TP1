#include "Teste_Estado.h"

const std::string Teste_Estado::ESTADO_VALIDO = "FAZENDO";
const std::string Teste_Estado::ESTADO_INVALIDO = "NAO FEITO";

void Teste_Estado::construtor(){
    estado = new Estado();
    estado_do_teste = SUCESSO;
}

void Teste_Estado::destrutor(){
    delete estado;
}

void Teste_Estado::testarCenarioSucesso(){
    try{
        estado->setEstado(ESTADO_VALIDO);
        if (estado->getEstado() != ESTADO_VALIDO)
            estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
        estado_do_teste = FALHA;
    }
}

void Teste_Estado::testarCenarioFalha(){
    try{
        estado->setEstado(ESTADO_INVALIDO);
        estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
        /*if (estado->getEstado() == ESTADO_INVALIDO)
            estado_do_teste = FALHA;*/
        // A exceção era esperada.
    }
}

int Teste_Estado::run(){
    construtor();
    testarCenarioSucesso();
    testarCenarioFalha();
    destrutor();
    return estado_do_teste;
}
