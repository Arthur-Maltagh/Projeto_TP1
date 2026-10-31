#ifndef ISERAPRESENTACAO_H_INCLUDED
#define ISERAPRESENTACAO_H_INCLUDED

/**
 * @file ISerAutenticacao.h
 * @brief Declaração da interface de serviço do módulo de autenticação.
 */

#include "EMAIL.h"
#include "Senha.h"

/**
 * @brief Interface de serviço do módulo de autenticação.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MSAU e usada pelo módulo MAAU.
 */
class ISerAutenticacao {
public:
    /**
     * @brief Verifica se as credenciais correspondem a uma conta.
     *
     * @param email Email informado pelo usuário.
     * @param senha Senha informada pelo usuário.
     * @return true se existe pessoa com o email e a senha informados;
     *         false caso contrário.
     */
    virtual bool autenticar(const EMAIL &email, const Senha &senha) = 0;

    /** @brief Destrutor virtual. */
    virtual ~ISerAutenticacao() {}
};


#endif // ISERAPRESENTACAO_H_INCLUDED
