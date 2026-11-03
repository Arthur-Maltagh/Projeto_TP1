#include "StubISerPessoa.h"

using namespace std;

string chaveDe(Pessoa pessoa) {
    return pessoa.getEmail().getEMAIL();
}
string chaveDe(EMAIL email){
    return email.getEMAIL();
}

bool StubISerPessoa::criar(const Pessoa &pessoa) {
    string chave = chaveDe(pessoa);

    for (list<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice) {
        if (chaveDe(*indice) == chave)
            return false;               // email ja cadastrado
    }
    pessoas.push_back(pessoa);
    return true;
}

bool StubISerPessoa::ler(Pessoa *pessoa) {
    string chave = chaveDe(*pessoa);

    for (list<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice) {
        if (chaveDe(*indice) == chave) {
            *pessoa = *indice;              // devolve todos os dados
            return true;
        }
    }
    return false;
}

bool StubISerPessoa::atualizar(const Pessoa &pessoa) {
    string chave = chaveDe(pessoa);

    for (list<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice) {
        if (chaveDe(*indice) == chave) {
            *indice = pessoa;
            return true;
        }
    }
    return false;
}

bool StubISerPessoa::excluir(const EMAIL &email) {
    string chave = chaveDe(email);

    for (list<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice) {
        if (chaveDe(*indice) == chave) {
            pessoas.erase(indice);
            return true;
        }
    }
    return false;
}

bool StubISerPessoa::listar(list<EMAIL> *emails) {
    emails->clear();
    for (list<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice)
        emails->push_back(indice->getEmail());
    return true;
}
