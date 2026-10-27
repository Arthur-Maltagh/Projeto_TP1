#ifndef QUADRO_H_INCLUDED
#define QUADRO_H_INCLUDED

#include "../dominios/Identificador.h"
#include "../dominios/nome.h"
#include "../dominios/Limite.h"

class Quadro {
private:
    Identificador identificador;
    Nome nome;
    Limite limite;

public:
    void setIdentificador(const Identificador& identificador);
    Identificador getIdentificador() const;

    void setNome(const Nome& nome);
    Nome getNome() const;

    void setLimite(const Limite& limite);
    Limite getLimite() const;
};


#endif // QUADRO_H_INCLUDED
