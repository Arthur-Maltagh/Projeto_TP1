#include "ContainerPessoa.h"

using namespace std;


// Recebem o objeto por valor para nao exigir getters const.
static string chaveDe(Pessoa pessoa){
    return pessoa.getEmail().getEMAIL();
}
static string chaveDe(EMAIL email){
    return email.getEMAIL();
}

vector<Pessoa>::iterator ContainerPessoa::localizar(const string &chave) {
    for (vector<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice) {
        if (chaveDe(*indice) == chave)
            return indice;
    }
    return pessoas.end();
}

bool ContainerPessoa::incluir(const Pessoa &pessoa) {
    if (localizar(chaveDe(pessoa)) != pessoas.end())
        return false;                   // email ja cadastrado
    pessoas.push_back(pessoa);
    return true;
}

bool ContainerPessoa::remover(const EMAIL &email) {
    vector<Pessoa>::iterator indice = localizar(chaveDe(email));
    if (indice == pessoas.end())
        return false;
    pessoas.erase(indice);
    return true;
}

bool ContainerPessoa::pesquisar(Pessoa *pessoa) {
    vector<Pessoa>::iterator indice = localizar(chaveDe(*pessoa));
    if (indice == pessoas.end())
        return false;
    *pessoa = *indice;                      // devolve todos os dados
    return true;
}

bool ContainerPessoa::atualizar(const Pessoa &pessoa) {
    vector<Pessoa>::iterator indice = localizar(chaveDe(pessoa));
    if (indice == pessoas.end())
        return false;
    *indice = pessoa;
    return true;
}

void ContainerPessoa::listar(list<EMAIL> *emails) {
    emails->clear();
    for (vector<Pessoa>::iterator indice = pessoas.begin(); indice != pessoas.end(); ++indice)
        emails->push_back(indice->getEmail());
}
