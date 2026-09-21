#include "pessoa.h"

void Pessoa::setEmail(const EMAIL& email) {
    this->email = email;
}

EMAIL Pessoa::getEmail() const {
    return email;
}

void Pessoa::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Pessoa::getNome() const {
    return nome;
}

void Pessoa::setSenha(const Senha& senha) {
    this->senha = senha;
}

Senha Pessoa::getSenha() const {
    return senha;
}

/*
inline void Pessoa::setPapel(const Papel& papel) {
    this->papel = papel;
}

inline Papel Pessoa::getPapel() const {
    return papel;
}
*/
