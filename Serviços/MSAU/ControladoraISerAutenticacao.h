#ifndef CONTROLADORAISERAUTENTICACAO_H_INCLUDED
#define CONTROLADORAISERAUTENTICACAO_H_INCLUDED

/**
 * @file CntrISerAutenticacao.h
 * @brief Declaracao da controladora de servico do modulo de autenticacao.
 */

#include "EMAIL.h"
#include "ISerAutenticacao.h"
#include "Senha.h"

class ISerPessoa;

/**
 * @brief Controladora de servico do modulo de autenticacao (MSAU).
 *
 * Realiza a interface ISerAutenticacao. Nao guarda dados: consulta a
 * pessoa pelo servico de pessoas (ISerPessoa) e compara a senha.
 */
class CntrISerAutenticacao : public ISerAutenticacao {
private:
    ISerPessoa *cntrISerPessoa;
public:
    /** @brief Cria a controladora sem servico de pessoas associado. */
    CntrISerAutenticacao() : cntrISerPessoa(nullptr) {}

    bool autenticar(const EMAIL &email, const Senha &senha);

    /**
     * @brief Informa o servico de pessoas usado para consultar as contas.
     * @param cntr Ponteiro para uma implementacao de ISerPessoa.
     */
    void setCntrISerPessoa(ISerPessoa *cntr) { cntrISerPessoa = cntr; }
};

#endif // CONTROLADORAISERAUTENTICACAO_H_INCLUDED
