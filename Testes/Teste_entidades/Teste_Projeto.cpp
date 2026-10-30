#include <iostream>
#include <stdexcept>
#include "teste_projeto.h"

using namespace std;

void Teste_Projeto::construtor(){
    projeto = new Projeto();
    estado = SUCESSO;
}

void Teste_Projeto::destrutor(){
    delete projeto;
}

void Teste_Projeto::testa_valor_valido(){
    try{
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;

        identificador.setIdentificador(VALOR_IDENTIFICADOR);
        nome.setNome(VALOR_NOME);
        descricao.setTexto(VALOR_DESCRICAO);
        inicio.setTimestamp(VALOR_TIMESTAMP);
        termino.setTimestamp(VALOR_TIMESTAMP);

        projeto->setIdentificador(identificador);
        projeto->setNome(nome);
        projeto->setDescricao(descricao);
        projeto->setInicio(inicio);
        projeto->setTermino(termino);

        if(projeto->getIdentificador().getIdentificador() != VALOR_IDENTIFICADOR)
            estado = FALHA;

        if(projeto->getNome().getNome() != VALOR_NOME)
            estado = FALHA;

        if(projeto->getDescricao().getTexto() != VALOR_DESCRICAO)
            estado = FALHA;

        if(projeto->getInicio().getTimestamp() != VALOR_TIMESTAMP)
            estado = FALHA;

        if(projeto->getTermino().getTimestamp() != VALOR_TIMESTAMP)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int Teste_Projeto::run(){
    construtor();
    testa_valor_valido();
    destrutor();

    return estado;
}
