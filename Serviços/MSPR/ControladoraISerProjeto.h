#ifndef CONTROLADORAISERPROJETO_H_INCLUDED
#define CONTROLADORAISERPROJETO_H_INCLUDED

/**
 * @file ControladoraISerProjeto.h
 * @brief Declara a controladora de serviço do módulo de projetos.
 */

#include <list>
#include "ContainerProjeto.h"
#include "ISerProjeto.h"

class ISerQuadro;

/**
 * @brief Implementa os serviços de projeto e suas regras de negócio.
 *
 * A controladora implementa ISerProjeto e delega o armazenamento ao
 * ContainerProjeto. Um projeto só pode ser excluído quando não possui
 * quadros associados. A exclusão dos quadros deve ser feita previamente.
 */
class CntrISerProjeto : public ISerProjeto {
private:
    ContainerProjeto container;
    ISerQuadro *cntrISerQuadro;

public:
    /** @brief Constrói a controladora sem serviço de quadros associado. */
    CntrISerProjeto() : cntrISerQuadro(nullptr) {}

    /** @brief Cria um projeto e registra seu gestor. */
    bool criar(const Projeto &projeto, const EMAIL &gestor);

    /** @brief Lê os dados do projeto indicado pelo identificador recebido. */
    bool ler(Projeto *projeto);

    /** @brief Atualiza os dados de um projeto sem alterar sua chave ou gestor. */
    bool atualizar(const Projeto &projeto);

    /** @brief Informa quantos quadros estão associados ao projeto. */
    bool contarQuadros(const Identificador &projeto, unsigned int *quantidade);

    /**
     * @brief Exclui um projeto somente quando não possui quadros associados.
     * @return false se o projeto não existe, possui quadros ou a consulta
     *         ao serviço de quadros não pôde ser realizada.
     */
    bool excluir(const Identificador &projeto);

    /** @brief Lista os identificadores dos projetos cadastrados. */
    bool listar(std::list<Identificador> *projetos);

    /** @brief Informa se a pessoa é gestora de algum projeto. */
    bool possuiProjetos(const EMAIL &gestor);

    /**
     * @brief Conecta o serviço de quadros usado para consultar dependências.
     * @param cntr Implementação de ISerQuadro.
     */
    void setCntrISerQuadro(ISerQuadro *cntr) { cntrISerQuadro = cntr; }
};

#endif // CONTROLADORAISERPROJETO_H_INCLUDED
