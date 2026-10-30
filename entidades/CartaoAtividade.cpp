#include "CartaoAtividades.h"

void CartaoDeAtividade::setIdentificador(const Identificador& identificador) {
    this->identificador = identificador;
}

Identificador CartaoDeAtividade::getIdentificador() const {
    return identificador;
}

void CartaoDeAtividade::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome CartaoDeAtividade::getNome() const {
    return nome;
}

void CartaoDeAtividade::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

Texto CartaoDeAtividade::getDescricao() const {
    return descricao;
}

void CartaoDeAtividade::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}

Prioridade CartaoDeAtividade::getPrioridade() const {
    return prioridade;
}

void CartaoDeAtividade::setEstado(const Estado& estado) {
    this->estado = estado;
}

Estado CartaoDeAtividade::getEstado() const {
    return estado;
}

void CartaoDeAtividade::setTamanho(const Tamanho& tamanho) {
    this->tamanho = tamanho;
}

Tamanho CartaoDeAtividade::getTamanho() const {
    return tamanho;
}

void CartaoDeAtividade::setEntrada(const Timestamp& entrada) {
    this->entrada = entrada;
}

Timestamp CartaoDeAtividade::getEntrada() const {
    return entrada;
}

void CartaoDeAtividade::setInicio(const Timestamp& inicio) {
    this->inicio = inicio;
}

Timestamp CartaoDeAtividade::getInicio() const {
    return inicio;
}

void CartaoDeAtividade::setTermino(const Timestamp& termino) {
    this->termino = termino;
}

Timestamp CartaoDeAtividade::getTermino() const {
    return termino;
}

