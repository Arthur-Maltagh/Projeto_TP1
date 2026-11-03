#ifndef CONTROLADORAISERPESSOA_H_INCLUDED
#define CONTROLADORAISERPESSOA_H_INCLUDED

/**
 * @file CntrISerPessoa.h
 * @brief Declaracao da controladora de servico do modulo de pessoas.
 */

#include <list>
#include "ContainerPessoa.h"
#include "EMAIL.h"
#include "ISerPessoa.h"
#include "Pessoa.h"

class ISerProjeto;
class ISerCartao;

/**
 * @brief Controladora de servico do modulo de pessoas (MSPE).
 *
 * Realiza a interface ISerPessoa. Aplica a logica de negocio e usa um
 * ContainerPessoa para armazenar os dados. Nao interage com o usuario.
 */
class CntrISerPessoa : public ISerPessoa {
private:
    ContainerPessoa container;
    ISerProjeto *cntrISerProjeto;
    ISerCartao *cntrISerCartao;
public:
    /** @brief Método construtor que inicializa a controladora sem servicos de projeto e de cartao. */
    CntrISerPessoa() : cntrISerProjeto(nullptr), cntrISerCartao(nullptr) {}

    bool criar(const Pessoa &pessoa);
    bool ler(Pessoa *pessoa);
    bool atualizar(const Pessoa &pessoa);
    bool excluir(const EMAIL &email);
    bool listar(std::list<EMAIL> *emails);

    /**
     * @brief Informa o servico de projetos, usado na exclusao de pessoa.
     * @param cntr Ponteiro para uma implementacao de ISerProjeto. Se for
     *        nulo, a existencia de projetos nao e verificada.
     */
    void setCntrISerProjeto(ISerProjeto *cntr_projeto) {
         cntrISerProjeto = cntr_projeto;
    }

    /**
     * @brief Informa o servico de cartoes, usado na exclusao de pessoa.
     * @param cntr Ponteiro para uma implementacao de ISerCartao. Se for
     *        nulo, a existencia de cartoes nao e verificada.
     */
    void setCntrISerCartao(ISerCartao *cntr_cartao){
         cntrISerCartao = cntr_cartao;
        }
};

#endif // CONTROLADORAISERPESSOA_H_INCLUDED
