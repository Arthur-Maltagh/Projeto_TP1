#ifndef ISERPROJETO_H_INCLUDED
#define ISERPROJETO_H_INCLUDED

/**
 * @file ISerProjeto.h
 * @brief Declaração da interface de serviço do módulo de projetos.
 */

#include <list>
#include "EMAIL.h"
#include "Identificador.h"
#include "Projeto.h"

/**
 * @brief Interface de serviço do módulo de projetos.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MSPR. Corresponde aos serviços 6 a 10 da
 * especificação. Todos os métodos retornam false quando o serviço
 * não pôde ser realizado.
 */
class ISerProjeto {
public:
    /**
     * @brief Cria um projeto.
     * @param projeto Dados do novo projeto.
     * @param gestor Email da pessoa que cria o projeto e passa a ser
     *        o seu gestor.
     * @return false se já existe projeto com o mesmo identificador.
     */
    virtual bool criar(const Projeto &projeto, const EMAIL &gestor) = 0;

    /**
     * @brief Lê os dados de um projeto.
     * @param projeto Na entrada, contém o identificador do projeto.
     *        Na saída, contém todos os dados do projeto.
     * @return false se o projeto não existe.
     */
    virtual bool ler(Projeto *projeto) = 0;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * O identificador não pode ser alterado.
     *
     * @param projeto Novos dados, com o identificador do projeto.
     * @return false se o projeto não existe.
     */
    virtual bool atualizar(const Projeto &projeto) = 0;

    /**
     * @brief Exclui um projeto e, em cascata, os seus quadros e cartões.
     * @param projeto Identificador do projeto a excluir.
     * @return false se o projeto não existe.
     */
    virtual bool excluir(const Identificador &projeto) = 0;

    /**
     * @brief Lista os identificadores de todos os projetos.
     * @param projetos Recebe os identificadores dos projetos.
     * @return true se a listagem foi realizada.
     */
    virtual bool listar(std::list<Identificador> *projetos) = 0;

    /**
     * @brief Informa se uma pessoa é gestora de algum projeto.
     * @param gestor Email da pessoa consultada.
     * @return true se existe ao menos um projeto sob a gestão da pessoa.
     */
    virtual bool possuiProjetos(const EMAIL &gestor) = 0;

    /** @brief Destrutor virtual. */
    virtual ~ISerProjeto() {}
};

#endif // ISERPROJETO_H_INCLUDED
