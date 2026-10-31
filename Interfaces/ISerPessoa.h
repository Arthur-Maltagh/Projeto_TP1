#ifndef ISERPESSOA_H_INCLUDED
#define ISERPESSOA_H_INCLUDED

/**
 * @file ISerPessoa.h
 * @brief Declaração da interface de serviço do módulo de pessoas.
 */

#include <list>
#include "EMAIL.h"
#include "Pessoa.h"

/**
 * @brief Interface de serviço do módulo de pessoas.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MSPE. Corresponde aos serviços 1 a 5 da
 * especificação. Todos os métodos retornam false quando o serviço
 * não pôde ser realizado.
 */
class ISerPessoa {
public:
    /**
     * @brief Cria uma pessoa.
     * @param pessoa Dados da nova pessoa.
     * @return false se já existe pessoa com o mesmo email.
     */
    virtual bool criar(const Pessoa &pessoa) = 0;

    /**
     * @brief Lê os dados de uma pessoa.
     * @param pessoa Na entrada, contém o email da pessoa procurada.
     *        Na saída, contém todos os dados da pessoa.
     * @return false se não existe pessoa com o email informado.
     */
    virtual bool ler(Pessoa *pessoa) = 0;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * O email identifica a pessoa e não pode ser alterado.
     *
     * @param pessoa Novos dados, com o email da pessoa a atualizar.
     * @return false se não existe pessoa com o email informado.
     */
    virtual bool atualizar(const Pessoa &pessoa) = 0;

    /**
     * @brief Exclui uma pessoa.
     *
     * A exclusão não pode gerar inconsistência: é recusada se a pessoa
     * é gestora de algum projeto ou desenvolvedora de algum cartão.
     *
     * @param email Email da pessoa a excluir.
     * @return false se a pessoa não existe ou se possui projetos ou
     *         cartões associados.
     */
    virtual bool excluir(const EMAIL &email) = 0;

    /**
     * @brief Lista os emails de todas as pessoas.
     * @param emails Recebe os emails das pessoas cadastradas.
     * @return true se a listagem foi realizada.
     */
    virtual bool listar(std::list<EMAIL> *emails) = 0;

    /** @brief Destrutor virtual. */
    virtual ~ISerPessoa() {}
};

#endif // ISERPESSOA_H_INCLUDED
