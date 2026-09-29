#include <iostream>
#include <stdexcept>
#include "../../entidades/pessoa.h"
#include "teste_pessoa.h"

using namespace std;

void Teste_Pessoa::construtor(){
    pessoa = new Pessoa();
    estado = SUCESSO;
}

void Teste_Pessoa::destrutor(){
    delete pessoa;
}

void Teste_Pessoa::testa_valor_valido(){
    try{
        EMAIL email;
        Nome nome;
        Senha senha;

        email.setEMAIL(VALOR_EMAIL);
        nome.setNome(VALOR_NOME);
        senha.setSenha(VALOR_SENHA);

        pessoa->setEmail(email);
        pessoa->setNome(nome);
        pessoa->setSenha(senha);

        if(pessoa->getEmail().getEMAIL() != VALOR_EMAIL)
            estado = FALHA;

        if(pessoa->getNome().getNome() != VALOR_NOME)
            estado = FALHA;

        if(pessoa->getSenha().getSenha() != VALOR_SENHA)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int Teste_Pessoa::run(){
    construtor();
    testa_valor_valido();
    destrutor();

    return estado;
}
