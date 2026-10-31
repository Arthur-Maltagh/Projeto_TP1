#ifndef STUBISERPESSOA_H_INCLUDED
#define STUBISERPESSOA_H_INCLUDED

/**
 * @file StubISerPessoa.h
 * @brief Declaracao do stub da interface de servico de pessoas.
 */

#include <list>
#include "EMAIL.h"
#include "ISerPessoa.h"
#include "Pessoa.h"

/**
 * @brief Implementacao falsa de ISerPessoa para testar a apresentacao.
 *
 * Guarda as pessoas em uma lista em memoria e nao aplica regra de negocio
 * alem de impedir email repetido. Serve apenas para testes: o servico real
 * e implementado pelo modulo MSPE.
 */
class StubISerPessoa : public ISerPessoa {
private:
    std::list<Pessoa> pessoas;
public:
    bool criar(const Pessoa &pessoa);
    bool ler(Pessoa *pessoa);
    bool atualizar(const Pessoa &pessoa);
    bool excluir(const EMAIL &email);
    bool listar(std::list<EMAIL> *emails);
};


#endif // STUBISERPESSOA_H_INCLUDED
