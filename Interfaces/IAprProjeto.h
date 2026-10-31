#ifndef IAPRPROJETO_H_INCLUDED
#define IAPRPROJETO_H_INCLUDED

/**
 * @file IAprProjeto.h
 * @brief Declaração da interface de apresentação do módulo de projetos.
 */

#include "EMAIL.h"
#include "IAprQuadro.h"
#include "ISerPessoa.h"
#include "ISerProjeto.h"

/**
 * @brief Interface de apresentação do módulo de projetos.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MAPR e usada pelo módulo MAIC. A partir de um
 * projeto, o usuário acessa os quadros por meio de IAprQuadro.
 */
class IAprProjeto {
public:
    /**
     * @brief Executa os serviços de projeto para um usuário autenticado.
     *
     * Permite ler, listar e, conforme o papel do usuário, criar, atualizar
     * e excluir projetos, além de acessar os quadros de um projeto.
     *
     * @param email Email do usuário autenticado.
     */
    virtual void executar(const EMAIL &email) = 0;

    /**
     * @brief Informa qual implementação do serviço de projetos usar.
     * @param cntr Ponteiro para uma implementação de ISerProjeto.
     */
    virtual void setCntrISerProjeto(ISerProjeto *cntr) = 0;

    /**
     * @brief Informa qual implementação do serviço de pessoas usar.
     *
     * Usada para consultar o papel do usuário autenticado.
     *
     * @param cntr Ponteiro para uma implementação de ISerPessoa.
     */
    virtual void setCntrISerPessoa(ISerPessoa *cntr) = 0;

    /**
     * @brief Informa qual implementação da apresentação de quadros usar.
     * @param cntr Ponteiro para uma implementação de IAprQuadro.
     */
    virtual void setCntrIAprQuadro(IAprQuadro *cntr) = 0;

    /** @brief Destrutor virtual. */
    virtual ~IAprProjeto() {}
};


#endif // IAPRPROJETO_H_INCLUDED
