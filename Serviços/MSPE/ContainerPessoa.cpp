#include "ContainerPessoa.h"

using namespace std;

namespace {
    // Recebem o objeto por valor para nao exigir getters const.
    string chaveDe(Pessoa pessoa) { return pessoa.getEmail().getEMAIL(); }
    string chaveDe(EMAIL email)   { return email.getEMAIL(); }
}

bool ContainerPessoa::incluir(const Pessoa &pessoa) {
    return pessoas.insert(make_pair(chaveDe(pessoa), pessoa)).second;
}

bool ContainerPessoa::remover(const EMAIL &email) {
    return pessoas.erase(chaveDe(email)) > 0;
}

bool ContainerPessoa::pesquisar(Pessoa *pessoa) {
    map<string, Pessoa>::iterator it = pessoas.find(chaveDe(*pessoa));
    if (it == pessoas.end())
        return false;
    *pessoa = it->second;
    return true;
}

bool ContainerPessoa::atualizar(const Pessoa &pessoa) {
    map<string, Pessoa>::iterator it = pessoas.find(chaveDe(pessoa));
    if (it == pessoas.end())
        return false;
    it->second = pessoa;
    return true;
}

void ContainerPessoa::listar(list<EMAIL> *emails) {
    emails->clear();
    for (map<string, Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it)
        emails->push_back(it->second.getEmail());
}
