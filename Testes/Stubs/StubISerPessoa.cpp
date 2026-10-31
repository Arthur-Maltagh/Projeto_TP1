#include "StubISerPessoa.h"

using namespace std;

namespace {
    // Recebem o objeto por valor para nao exigir getters const nas classes
    // de dominio e de entidade.
    string chaveDe(Pessoa pessoa) { return pessoa.getEmail().getEMAIL(); }
    string chaveDe(EMAIL email)   { return email.getEMAIL(); }
}

bool StubISerPessoa::criar(const Pessoa &pessoa) {
    string chave = chaveDe(pessoa);

    for (list<Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (chaveDe(*it) == chave)
            return false;               // email ja cadastrado
    }
    pessoas.push_back(pessoa);
    return true;
}

bool StubISerPessoa::ler(Pessoa *pessoa) {
    string chave = chaveDe(*pessoa);

    for (list<Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (chaveDe(*it) == chave) {
            *pessoa = *it;              // devolve todos os dados
            return true;
        }
    }
    return false;
}

bool StubISerPessoa::atualizar(const Pessoa &pessoa) {
    string chave = chaveDe(pessoa);

    for (list<Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (chaveDe(*it) == chave) {
            *it = pessoa;
            return true;
        }
    }
    return false;
}

bool StubISerPessoa::excluir(const EMAIL &email) {
    string chave = chaveDe(email);

    for (list<Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (chaveDe(*it) == chave) {
            pessoas.erase(it);
            return true;
        }
    }
    return false;
}

bool StubISerPessoa::listar(list<EMAIL> *emails) {
    emails->clear();
    for (list<Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it)
        emails->push_back(it->getEmail());
    return true;
}
