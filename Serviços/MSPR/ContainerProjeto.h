#ifndef CONTAINERPROJETO_H_INCLUDED
#define CONTAINERPROJETO_H_INCLUDED

/**
 * @file ContainerProjeto.h
 * @brief Declara o contêiner em memória dos projetos.
 */

#include <list>
#include <string>
#include <vector>
#include "EMAIL.h"
#include "Identificador.h"
#include "Projeto.h"

/**
 * @brief Armazena projetos e o email da pessoa que os criou.
 *
 * O identificador é a chave de cada projeto. O contêiner não aplica regras
 * de autorização nem executa operações sobre quadros; essas responsabilidades
 * pertencem à controladora de serviço.
 */
class ContainerProjeto {
private:
    /** @brief Registro interno que associa um projeto ao seu gestor. */
    struct RegistroProjeto {
        Projeto projeto;
        EMAIL gestor;
    };

    std::vector<RegistroProjeto> projetos;

    /** @brief Localiza um projeto pelo identificador textual. */
    std::vector<RegistroProjeto>::iterator localizar(const std::string &chave);

public:
    /**
     * @brief Inclui um projeto e registra quem o criou.
     * @param projeto Projeto a armazenar.
     * @param gestor Email do gestor que criou o projeto.
     * @return false se já existe projeto com o mesmo identificador.
     */
    bool incluir(const Projeto &projeto, const EMAIL &gestor);

    /**
     * @brief Remove um projeto pelo identificador.
     * @param identificador Chave do projeto.
     * @return false se o projeto não existe.
     */
    bool remover(const Identificador &identificador);

    /**
     * @brief Pesquisa um projeto pelo identificador.
     * @param projeto Na entrada, contém a chave; na saída, recebe os dados.
     * @return false se o projeto não existe ou se o ponteiro é nulo.
     */
    bool pesquisar(Projeto *projeto);

    /**
     * @brief Substitui os dados de um projeto existente.
     * @param projeto Novos dados, identificados pela chave original.
     * @return false se o projeto não existe.
     */
    bool atualizar(const Projeto &projeto);

    /**
     * @brief Copia para a lista os identificadores dos projetos cadastrados.
     * @param identificadores Lista que receberá as chaves.
     */
    void listar(std::list<Identificador> *identificadores);

    /**
     * @brief Verifica se uma pessoa criou ao menos um projeto.
     * @param gestor Email da pessoa consultada.
     * @return true se ela é gestora de algum projeto.
     */
    bool possuiProjetos(const EMAIL &gestor);
};

#endif // CONTAINERPROJETO_H_INCLUDED
