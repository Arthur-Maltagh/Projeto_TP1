#include <iostream>
#include <stdexcept>
#include "Teste_Cartaoatividade.h"

using namespace std;

void Teste_CartaoDeAtividade::construtor(){
    cartao = new CartaoDeAtividade();
    estado = SUCESSO;
}

void Teste_CartaoDeAtividade::destrutor(){
    delete cartao;
}

void Teste_CartaoDeAtividade::testa_valor_valido(){
    try{
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Estado estado_dominio;
        Tamanho tamanho;
        Timestamp entrada;
        Timestamp inicio;
        Timestamp termino;

        identificador.setIdentificador(VALOR_IDENTIFICADOR);
        nome.setNome(VALOR_NOME);
        descricao.setTexto(VALOR_DESCRICAO);
        prioridade.setPrioridade(VALOR_PRIORIDADE);
        estado_dominio.setEstado(VALOR_ESTADO);
        tamanho.setTamanho(VALOR_TAMANHO);
        entrada.setTimestamp(VALOR_TIMESTAMP);
        inicio.setTimestamp(VALOR_TIMESTAMP);
        termino.setTimestamp(VALOR_TIMESTAMP);

        cartao->setIdentificador(identificador);
        cartao->setNome(nome);
        cartao->setDescricao(descricao);
        cartao->setPrioridade(prioridade);
        cartao->setEstado(estado_dominio);
        cartao->setTamanho(tamanho);
        cartao->setEntrada(entrada);
        cartao->setInicio(inicio);
        cartao->setTermino(termino);

        if(cartao->getIdentificador().getIdentificador() != VALOR_IDENTIFICADOR)
            estado = FALHA;

        if(cartao->getNome().getNome() != VALOR_NOME)
            estado = FALHA;

        if(cartao->getDescricao().getTexto() != VALOR_DESCRICAO)
            estado = FALHA;

        if(cartao->getPrioridade().getPrioridade() != VALOR_PRIORIDADE)
            estado = FALHA;

        if(cartao->getEstado().getEstado() != VALOR_ESTADO)
            estado = FALHA;

        if(cartao->getTamanho().getTamanho() != VALOR_TAMANHO)
            estado = FALHA;

        if(cartao->getEntrada().getTimestamp() != VALOR_TIMESTAMP)
            estado = FALHA;

        if(cartao->getInicio().getTimestamp() != VALOR_TIMESTAMP)
            estado = FALHA;

        if(cartao->getTermino().getTimestamp() != VALOR_TIMESTAMP)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int Teste_CartaoDeAtividade::run(){
    construtor();
    testa_valor_valido();
    destrutor();

    return estado;
}
