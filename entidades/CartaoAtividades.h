#ifndef CARTAOATIVIDADES_H_INCLUDED
#define CARTAOATIVIDADES_H_INCLUDED

#include "Identificador.h"
#include "nome.h"
#include "Texto.h"
#include "Prioridade.h"
#include "Estado.h"
#include "Tamanho.h"
#include "Timestamp.h"

class CartaoDeAtividade {
private:
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Estado estado;
    Tamanho tamanho;
    Timestamp entrada;
    Timestamp inicio;
    Timestamp termino;

public:
    void setIdentificador(const Identificador& identificador);
    Identificador getIdentificador() const;

    void setNome(const Nome& nome);
    Nome getNome() const;

    void setDescricao(const Texto& descricao);
    Texto getDescricao() const;

    void setPrioridade(const Prioridade& prioridade);
    Prioridade getPrioridade() const;

    void setEstado(const Estado& estado);
    Estado getEstado() const;

    void setTamanho(const Tamanho& tamanho);
    Tamanho getTamanho() const;

    void setEntrada(const Timestamp& entrada);
    Timestamp getEntrada() const;

    void setInicio(const Timestamp& inicio);
    Timestamp getInicio() const;

    void setTermino(const Timestamp& termino);
    Timestamp getTermino() const;

};
#endif // CARTAOATIVIDADES_H_INCLUDED
