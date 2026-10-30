#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

#include "../dominios/Identificador.h"
#include "../dominios/nome.h"
#include "../dominios/Texto.h"
#include "../dominios/Timestamp.h"

class Projeto {
private:
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

public:
    void setIdentificador(const Identificador& identificador);
    Identificador getIdentificador() const;

    void setNome(const Nome& nome);
    Nome getNome() const;

    void setDescricao(const Texto& descricao);
    Texto getDescricao() const;

    void setInicio(const Timestamp& inicio);
    Timestamp getInicio() const;

    void setTermino(const Timestamp& termino);
    Timestamp getTermino() const;
};

#endif // PROJETO_H_INCLUDED
