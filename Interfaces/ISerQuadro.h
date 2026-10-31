#ifndef ISERQUADRO_H_INCLUDED
#define ISERQUADRO_H_INCLUDED

/**
 * @file ISerQuadro.h
 * @brief Declaração da interface de serviço de quadros.
 */

#include <list>
#include "Identificador.h"
#include "Quadro.h"

/**
 * @brief Interface de serviço de quadros.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MSQU. Corresponde aos serviços 11 a 15 da
 * especificação. Todos os métodos retornam false quando o serviço
 * não pôde ser realizado.
 */
class ISerQuadro {
public:
    /**
     * @brief Cria um quadro em um projeto.
     * @param quadro Dados do novo quadro.
     * @param projeto Identificador do projeto ao qual o quadro pertence.
     * @return false se já existe quadro com o mesmo identificador.
     */
    virtual bool criar(const Quadro &quadro, const Identificador &projeto) = 0;

    /**
     * @brief Lê os dados de um quadro.
     * @param quadro Na entrada, contém o identificador do quadro.
     *        Na saída, contém todos os dados do quadro.
     * @return false se o quadro não existe.
     */
    virtual bool ler(Quadro *quadro) = 0;

    /**
     * @brief Atualiza os dados de um quadro.
     *
     * O identificador não pode ser alterado. A atualização é recusada se
     * o novo limite for menor que o número atual de cartões em FAZENDO.
     *
     * @param quadro Novos dados, com o identificador do quadro.
     * @return false se o quadro não existe ou se o novo limite é menor
     *         que o WIP atual.
     */
    virtual bool atualizar(const Quadro &quadro) = 0;

    /**
     * @brief Exclui um quadro e, em cascata, os seus cartões.
     * @param quadro Identificador do quadro a excluir.
     * @return false se o quadro não existe.
     */
    virtual bool excluir(const Identificador &quadro) = 0;

    /**
     * @brief Lista os identificadores dos quadros de um projeto.
     * @param projeto Identificador do projeto.
     * @param quadros Recebe os identificadores dos quadros do projeto.
     * @return true se a listagem foi realizada (a lista pode ficar vazia).
     */
    virtual bool listar(const Identificador &projeto,
                        std::list<Identificador> *quadros) = 0;

    /**
     * @brief Exclui todos os quadros de um projeto, com os seus cartões.
     *
     * Usado pelo módulo de projetos na exclusão em cascata.
     *
     * @param projeto Identificador do projeto.
     * @return true se a exclusão foi realizada (inclusive quando o
     *         projeto não possui quadros).
     */
    virtual bool excluirPorProjeto(const Identificador &projeto) = 0;

    /** @brief Destrutor virtual. */
    virtual ~ISerQuadro() {}
};


#endif // ISERQUADRO_H_INCLUDED
