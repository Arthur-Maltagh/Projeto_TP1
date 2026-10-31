#ifndef IAPRAUTENTICACAO_H_INCLUDED
#define IAPRAUTENTICACAO_H_INCLUDED

/**
 * @file IAprAutenticacao.h
 * @brief Declaração da interface de apresentação do módulo de autenticação.
 */

#include "EMAIL.h"
#include "ISerAutenticacao.h"

/**
 * @brief Interface de apresentação do módulo de autenticação.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MAAU e usada pelo módulo MAIC.
 */
class IAprAutenticacao {
public:
    /**
     * @brief Executa o fluxo de autenticação com o usuário.
     *
     * Solicita email e senha, valida o formato dos dados digitados e
     * consulta o serviço de autenticação.
     *
     * @param email Recebe o email do usuário autenticado.
     * @return true se o usuário foi autenticado; false caso contrário.
     */
    virtual bool autenticar(EMAIL *email) = 0;

    /**
     * @brief Informa qual implementação do serviço de autenticação usar.
     * @param cntr Ponteiro para uma implementação de ISerAutenticacao.
     */
    virtual void setCntrISerAutenticacao(ISerAutenticacao *cntr) = 0;

    /** @brief Destrutor virtual. */
    virtual ~IAprAutenticacao() {}
};


#endif // IAPRAUTENTICACAO_H_INCLUDED
