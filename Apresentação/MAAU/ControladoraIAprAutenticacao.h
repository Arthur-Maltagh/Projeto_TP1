#ifndef CONTROLADORAIAPRAUTENTICACAO_H_INCLUDED
#define CONTROLADORAIAPRAUTENTICACAO_H_INCLUDED

/**
 * @file CntrIAprAutenticacao.h
 * @brief Declaracao da controladora de apresentacao do modulo de autenticacao.
 */

#include "EMAIL.h"
#include "IAprAutenticacao.h"
#include "ISerAutenticacao.h"

/**
 * @brief Controladora de apresentacao do modulo de autenticacao (MAAU).
 *
 * Realiza a interface IAprAutenticacao. Pede email e senha ao usuario,
 * valida o formato dos dados digitados e consulta o servico de
 * autenticacao pela interface ISerAutenticacao.
 */


class CntrIAprAutenticacao : public IAprAutenticacao {
private:
    ISerAutenticacao *cntrISerAutenticacao;
public:
    /** @brief Cria a controladora sem servico associado. */
    CntrIAprAutenticacao() : cntrISerAutenticacao(nullptr) {}

    bool autenticar(EMAIL *email);

    /**
     * @brief Informa qual implementacao do servico de autenticacao usar.
     * @param cntr Ponteiro para uma implementacao de ISerAutenticacao.
     */
    void setCntrISerAutenticacao(ISerAutenticacao *cntr) { cntrISerAutenticacao = cntr; }
};

#endif // CONTROLADORAIAPRAUTENTICACAO_H_INCLUDED
