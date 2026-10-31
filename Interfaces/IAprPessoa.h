#ifndef IAPRPESSOA_H_INCLUDED
#define IAPRPESSOA_H_INCLUDED

/**
 * @file IAprPessoa.h
 * @brief Declaração da interface de apresentação do módulo de pessoas.
 */

#include "EMAIL.h"
#include "ISerPessoa.h"

/**
 * @brief Interface de apresentação do módulo de pessoas.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MAPE e usada pelo módulo MAIC.
 */
class IAprPessoa {
public:
    /**
     * @brief Executa o fluxo de criação de conta.
     *
     * Não exige autenticação prévia, pois a conta é criada antes do acesso
     * aos demais serviços.
     */
    virtual void criar() = 0;

    /**
     * @brief Executa os serviços de pessoa para um usuário autenticado.
     *
     * Permite ler, atualizar, excluir e listar pessoas.
     *
     * @param email Email do usuário autenticado.
     */
    virtual void executar(const EMAIL &email) = 0;

    /**
     * @brief Informa qual implementação do serviço de pessoas usar.
     * @param cntr Ponteiro para uma implementação de ISerPessoa.
     */
    virtual void setCntrISerPessoa(ISerPessoa *cntr) = 0;

    /** @brief Destrutor virtual. */
    virtual ~IAprPessoa() {}
};


#endif // IAPRPESSOA_H_INCLUDED
