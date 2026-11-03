#ifndef STUBSERAUTENTICACAO_H_INCLUDED
#define STUBSERAUTENTICACAO_H_INCLUDED

/**
 * @file StubISerAutenticacao.h
 * @brief Declaracao do stub da interface de servico de autenticacao.
 */

#include "EMAIL.h"
#include "ISerAutenticacao.h"
#include "Senha.h"

/**
 * @brief Implementacao falsa de ISerAutenticacao para testar a apresentacao.
 *
 * Aceita uma unica credencial fixa: email ana@teste.com e senha abc12.
 */
class StubISerAutenticacao : public ISerAutenticacao {
public:
    bool autenticar(const EMAIL &email, const Senha &senha);
};

#endif // STUBSERAUTENTICACAO_H_INCLUDED
