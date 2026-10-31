#ifndef CONTAINERPESSOA_H_INCLUDED
#define CONTAINERPESSOA_H_INCLUDED

/**
 * @file ContainerPessoa.h
 * @brief Declaracao do conteiner que armazena as pessoas do sistema.
 */

#include <list>
#include <map>
#include <string>
#include "EMAIL.h"
#include "Pessoa.h"

/**
 * @brief Conteiner que guarda as pessoas em memoria (armazenamento do MSPE).
 *
 * Cada pessoa e identificada pelo email. O conteiner so armazena e
 * recupera dados; as regras de negocio ficam na controladora.
 */
class ContainerPessoa {
private:
    std::map<std::string, Pessoa> pessoas;
public:
    /**
     * @brief Inclui uma pessoa.
     * @param pessoa Pessoa a incluir.
     * @return false se ja existe pessoa com o mesmo email.
     */
    bool incluir(const Pessoa &pessoa);

    /**
     * @brief Remove uma pessoa.
     * @param email Email da pessoa a remover.
     * @return false se nao existe pessoa com o email informado.
     */
    bool remover(const EMAIL &email);

    /**
     * @brief Pesquisa uma pessoa pelo email.
     * @param pessoa Na entrada, contem o email procurado. Na saida, contem
     *        todos os dados da pessoa encontrada.
     * @return false se nao existe pessoa com o email informado.
     */
    bool pesquisar(Pessoa *pessoa);

    /**
     * @brief Substitui os dados de uma pessoa ja armazenada.
     * @param pessoa Novos dados, com o email da pessoa a atualizar.
     * @return false se nao existe pessoa com o email informado.
     */
    bool atualizar(const Pessoa &pessoa);

    /**
     * @brief Recupera os emails de todas as pessoas armazenadas.
     * @param emails Recebe os emails.
     */
    void listar(std::list<EMAIL> *emails);
};

#endif // CONTAINERPESSOA_H_INCLUDED
