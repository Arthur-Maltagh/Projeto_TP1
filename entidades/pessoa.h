#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include "../dominios/EMAIL.h"
#include "../dominios/nome.h"
#include "../dominios/Senha.h"
#include "../dominios/Identificador.h"

//#include "papel.h"

using namespace std;

class Pessoa {
private:
    Identificador identificador;
    EMAIL email;
    Nome nome;
    Senha senha;
    //Papel papel;

public:

    void setIdentificador(const Identificador& identificador);
    Identificador getIdentificador() const;

    void setEmail(const EMAIL& email);
    EMAIL getEmail() const;

    void setNome(const Nome& nome);
    Nome getNome() const;

    void setSenha(const Senha& senha);
    Senha getSenha() const;

    //void setPapel(const Papel& papel);
    //Papel getPapel() const;
};

#endif // PESSOA_H_INCLUDED
