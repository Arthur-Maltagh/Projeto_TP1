#ifndef IAPRQUADRO_H_INCLUDED
#define IAPRQUADRO_H_INCLUDED

/**
 * @file IAprQuadro.h
 * @brief Declaração da interface de apresentação do módulo de quadros.
 */

#include "EMAIL.h"
#include "Identificador.h"
#include "ISerCartao.h"
#include "ISerPessoa.h"
#include "ISerQuadro.h"

/**
 * @brief Interface de apresentação do módulo de quadros e cartões.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MAQU e usada pelo módulo MAPR. Os serviços de
 * cartão de atividade são oferecidos a partir de um quadro.
 */
class IAprQuadro {
public:
    /**
     * @brief Executa os serviços de quadro e de cartão de um projeto.
     *
     * Permite ler e listar quadros e, conforme o papel do usuário, criar,
     * atualizar e excluir quadros e cartões, além de mover cartões e
     * consultar tempo de ciclo, lead time e WIP.
     *
     * @param email Email do usuário autenticado.
     * @param projeto Identificador do projeto cujos quadros serão tratados.
     */
    virtual void executar(const EMAIL &email, const Identificador &projeto) = 0;

    /**
     * @brief Informa qual implementação do serviço de quadros usar.
     * @param cntr Ponteiro para uma implementação de ISerQuadro.
     */
    virtual void setCntrISerQuadro(ISerQuadro *cntr) = 0;

    /**
     * @brief Informa qual implementação do serviço de cartões usar.
     * @param cntr Ponteiro para uma implementação de ISerCartao.
     */
    virtual void setCntrISerCartao(ISerCartao *cntr) = 0;

    /**
     * @brief Informa qual implementação do serviço de pessoas usar.
     *
     * Usada para consultar o papel do usuário e validar o desenvolvedor
     * de um cartão.
     *
     * @param cntr Ponteiro para uma implementação de ISerPessoa.
     */
    virtual void setCntrISerPessoa(ISerPessoa *cntr) = 0;

    /** @brief Destrutor virtual. */
    virtual ~IAprQuadro() {}
};


#endif // IAPRQUADRO_H_INCLUDED
