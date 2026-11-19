#include "ContainerProjeto.h"

using namespace std;

// Os getters dos domínios do projeto e do email não são const. Por isso,
// extraímos as chaves de cópias locais, sem modificar os objetos guardados.
static string chaveDe(const Identificador &identificador) {
    Identificador copia = identificador;
    return copia.getIdentificador();
}

static string chaveDe(const Projeto &projeto) {
    Identificador identificador = projeto.getIdentificador();
    return chaveDe(identificador);
}

static string chaveDe(const EMAIL &email) {
    EMAIL copia = email;
    return copia.getEMAIL();
}

vector<ContainerProjeto::RegistroProjeto>::iterator
ContainerProjeto::localizar(const string &chave) {
    for (vector<RegistroProjeto>::iterator it = projetos.begin();
         it != projetos.end(); ++it) {
        if (chaveDe(it->projeto) == chave)
            return it;
    }
    return projetos.end();
}

bool ContainerProjeto::incluir(const Projeto &projeto, const EMAIL &gestor) {
    if (localizar(chaveDe(projeto)) != projetos.end())
        return false;

    RegistroProjeto registro;
    registro.projeto = projeto;
    registro.gestor = gestor;
    projetos.push_back(registro);
    return true;
}

bool ContainerProjeto::remover(const Identificador &identificador) {
    vector<RegistroProjeto>::iterator it = localizar(chaveDe(identificador));
    if (it == projetos.end())
        return false;

    projetos.erase(it);
    return true;
}

bool ContainerProjeto::pesquisar(Projeto *projeto) {
    if (projeto == nullptr)
        return false;

    vector<RegistroProjeto>::iterator it = localizar(chaveDe(*projeto));
    if (it == projetos.end())
        return false;

    *projeto = it->projeto;
    return true;
}

bool ContainerProjeto::atualizar(const Projeto &projeto) {
    vector<RegistroProjeto>::iterator it = localizar(chaveDe(projeto));
    if (it == projetos.end())
        return false;

    // Somente os dados do projeto são substituídos. O gestor original é
    // preservado, pois representa a associação criada no cadastro.
    it->projeto = projeto;
    return true;
}

void ContainerProjeto::listar(list<Identificador> *identificadores) {
    if (identificadores == nullptr)
        return;

    identificadores->clear();
    for (vector<RegistroProjeto>::iterator it = projetos.begin();
         it != projetos.end(); ++it) {
        Identificador identificador = it->projeto.getIdentificador();
        identificadores->push_back(identificador);
    }
}

bool ContainerProjeto::possuiProjetos(const EMAIL &gestor) {
    const string chaveGestor = chaveDe(gestor);
    for (vector<RegistroProjeto>::iterator it = projetos.begin();
         it != projetos.end(); ++it) {
        if (chaveDe(it->gestor) == chaveGestor)
            return true;
    }
    return false;
}
