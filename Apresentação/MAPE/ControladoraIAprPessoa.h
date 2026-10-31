#ifndef CONTROLADORAIAPRPESSOA_H_INCLUDED
#define CONTROLADORAIAPRPESSOA_H_INCLUDED

/**
 * @file CntrIAprPessoa.h
 * @brief Declaracao da controladora de apresentacao do modulo de pessoas.
 */

#include "EMAIL.h"
#include "IAprPessoa.h"
#include "ISerPessoa.h"
#include "Pessoa.h"

/**
 * @brief Controladora de apresentacao do modulo de pessoas (MAPE).
 *
 * Realiza a interface IAprPessoa. Cuida do dialogo com o usuario (IU) e da
 * validacao dos dados digitados (VAL). A logica de negocio e o armazenamento
 * ficam no servico, acessado somente pela interface ISerPessoa.
 */
class CntrIAprPessoa : public IAprPessoa {
private:
    ISerPessoa *cntrISerPessoa;

    void mostrar(Pessoa &pessoa);
    void ler();
    void listar();
    void atualizar(const EMAIL &email);
    bool excluir(const EMAIL &email);
public:
    /** @brief Cria a controladora sem servico associado. */
    CntrIAprPessoa() : cntrISerPessoa(nullptr) {}

    /** @brief Executa o fluxo de criacao de conta. */
    void criar();

    /**
     * @brief Apresenta o menu de pessoas ao usuario autenticado.
     * @param email Email do usuario autenticado.
     */
    void executar(const EMAIL &email);

    /**
     * @brief Informa qual implementacao do servico de pessoas usar.
     * @param cntr Ponteiro para uma implementacao de ISerPessoa.
     */
    void setCntrISerPessoa(ISerPessoa *cntr) { cntrISerPessoa = cntr; }
};


#endif // CONTROLADORAIAPRPESSOA_H_INCLUDED
