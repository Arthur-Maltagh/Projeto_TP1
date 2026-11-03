#include "ControladoraISerPessoa.h"
#include "ISerCartao.h"
#include "ISerProjeto.h"

using namespace std;

bool CntrISerPessoa::criar(const Pessoa &pessoa) {
    return container.incluir(pessoa);
}

bool CntrISerPessoa::ler(Pessoa *pessoa) {
    return container.pesquisar(pessoa);
}

bool CntrISerPessoa::atualizar(const Pessoa &pessoa) {
    // O email identifica a pessoa e nao pode ser alterado: a busca e feita
    // por ele, entao so os demais dados sao substituidos.
    return container.atualizar(pessoa);
}

bool CntrISerPessoa::excluir(const EMAIL &email) {
    Pessoa pessoa;
    pessoa.setEmail(email);

    if (!container.pesquisar(&pessoa))
        return false;                       // pessoa nao existe

    // Regra: exclusao nao pode deixar o sistema inconsistente.
    if (cntrISerProjeto != nullptr && cntrISerProjeto->possuiProjetos(email))
        return false;                       // e gestora de projeto
    if (cntrISerCartao != nullptr && cntrISerCartao->possuiCartoes(email))
        return false;

    return container.remover(email);
}

bool CntrISerPessoa::listar(list<EMAIL> *emails) {
    container.listar(emails);
    return true;
}
