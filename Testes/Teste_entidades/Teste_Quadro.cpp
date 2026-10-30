#include <iostream>
#include <stdexcept>
#include "teste_quadro.h"

using namespace std;

void Teste_Quadro::construtor(){
    quadro = new Quadro();
    estado = SUCESSO;
}

void Teste_Quadro::destrutor(){
    delete quadro;
}

void Teste_Quadro::testa_valor_valido(){
    try{
        Identificador identificador;
        Nome nome;
        Limite limite;

        identificador.setIdentificador(VALOR_IDENTIFICADOR);
        nome.setNome(VALOR_NOME);
        limite.setLimite(VALOR_LIMITE);

        quadro->setIdentificador(identificador);
        quadro->setNome(nome);
        quadro->setLimite(limite);

        if(quadro->getIdentificador().getIdentificador() != VALOR_IDENTIFICADOR)
            estado = FALHA;

        if(quadro->getNome().getNome() != VALOR_NOME)
            estado = FALHA;

        if(quadro->getLimite().getLimite() != VALOR_LIMITE)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int Teste_Quadro::run(){
    construtor();
    testa_valor_valido();
    destrutor();

    return estado;
}
