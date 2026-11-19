#include "ControladoraISerProjeto.h"
#include "ISerQuadro.h"

using namespace std;

bool CntrISerProjeto::criar(const Projeto &projeto, const EMAIL &gestor) {
    return container.incluir(projeto, gestor);
}

bool CntrISerProjeto::ler(Projeto *projeto) {
    return container.pesquisar(projeto);
}

bool CntrISerProjeto::atualizar(const Projeto &projeto) {
    // O identificador é a chave usada para localizar o registro. Como não
    // existe operação para trocar a chave, ela permanece inalterada.
    return container.atualizar(projeto);
}

bool CntrISerProjeto::contarQuadros(const Identificador &projeto, unsigned int *quantidade) {
    if (quantidade == nullptr || cntrISerQuadro == nullptr)
        return false;

    // A consulta também valida a existência do projeto antes de consultar
    // o módulo de quadros.
    Projeto existente;
    existente.setIdentificador(projeto);
    if (!container.pesquisar(&existente))
        return false;

    list<Identificador> quadros;
    if (!cntrISerQuadro->listar(projeto, &quadros))
        return false;

    *quantidade = static_cast<unsigned int>(quadros.size());
    return true;
}

bool CntrISerProjeto::excluir(const Identificador &projeto) {
    Projeto existente;
    existente.setIdentificador(projeto);

    if (!container.pesquisar(&existente))
        return false;

    // Não há exclusão em cascata: um projeto só pode ser removido quando
    // o módulo de quadros confirma que não existem quadros associados.
    unsigned int quantidade = 0;
    if (!contarQuadros(projeto, &quantidade))
        return false;

    if (quantidade > 0)
        return false;

    return container.remover(projeto);
}

bool CntrISerProjeto::listar(list<Identificador> *projetos) {
    if (projetos == nullptr)
        return false;

    container.listar(projetos);
    return true;
}

bool CntrISerProjeto::possuiProjetos(const EMAIL &gestor) {
    return container.possuiProjetos(gestor);
}
