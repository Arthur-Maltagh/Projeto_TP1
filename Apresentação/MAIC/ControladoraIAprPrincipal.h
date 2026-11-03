#ifndef CONTROLADORAIAPRPRINCIPAL_H_INCLUDED
#define CONTROLADORAIAPRPRINCIPAL_H_INCLUDED

/**
 * @file CntrIAprPrincipal.h
 * @brief Declaracao da controladora do modulo de apresentacao principal.
 */

#include "EMAIL.h"
#include "IAprAutenticacao.h"
#include "IAprPessoa.h"
#include "IAprProjeto.h"

/**
 * @brief Controladora do modulo de apresentacao principal (MAIC).
 *
 * E a porta de entrada do sistema. Apresenta o menu inicial (entrar ou
 * criar conta) e, depois da autenticacao, o menu principal que leva aos
 * demais modulos de apresentacao. Conhece os outros modulos apenas pelas
 * interfaces IAprAutenticacao, IAprPessoa e IAprProjeto.
 */
class CntrIAprPrincipal {
private:
    IAprAutenticacao *cntrIAprAutenticacao;
    IAprPessoa *cntrIAprPessoa;
    IAprProjeto *cntrIAprProjeto;

    void executarSessao(const EMAIL &email);
public:
    /** @brief Cria a controladora sem modulos associados. */
    CntrIAprPrincipal(): cntrIAprAutenticacao(nullptr),cntrIAprPessoa(nullptr), cntrIAprProjeto(nullptr) {}

    /**
     * @brief Executa o sistema ate o usuario encerrar.
     *
     * Os tres modulos devem ter sido informados antes da chamada.
     */
    void executar();

    /**
     * @brief Informa o modulo de apresentacao de autenticacao.
     * @param cntr Ponteiro para uma implementacao de IAprAutenticacao.
     */
    void setCntrIAprAutenticacao(IAprAutenticacao *cntr) { cntrIAprAutenticacao = cntr; }

    /**
     * @brief Informa o modulo de apresentacao de pessoas.
     * @param cntr Ponteiro para uma implementacao de IAprPessoa.
     */
    void setCntrIAprPessoa(IAprPessoa *cntr) { cntrIAprPessoa = cntr; }

    /**
     * @brief Informa o modulo de apresentacao de projetos.
     * @param cntr Ponteiro para uma implementacao de IAprProjeto.
     */
    void setCntrIAprProjeto(IAprProjeto *cntr) { cntrIAprProjeto = cntr; }
};

#endif // CONTROLADORAIAPRPRINCIPAL_H_INCLUDED
