#ifndef STUBIAPRPROJETO_H_INCLUDED
#define STUBIAPRPROJETO_H_INCLUDED

/**
 * @file StubIAprProjeto.h
 * @brief Stub da interface de apresentacao do modulo de projetos.
 */

#include <iostream>
#include "EMAIL.h"
#include "IAprProjeto.h"

/**
 * @brief Implementacao falsa de IAprProjeto para testar o MAIC.
 *
 * Apenas informa que foi chamada e mostra o email recebido. Substitui o
 * modulo de projetos enquanto ele nao existe.
 */
class StubIAprProjeto : public IAprProjeto {
public:
    void executar(const EMAIL &email) {
        EMAIL copia = email;    // getters dos dominios nao sao const
        std::cout << "[stub] modulo de projetos chamado para o usuario "
                  << copia.getEMAIL() << std::endl;
    }
    void setCntrISerProjeto(ISerProjeto *) {}
    void setCntrISerPessoa(ISerPessoa *) {}
    void setCntrIAprQuadro(IAprQuadro *) {}
};

#endif // STUBIAPRPROJETO_H_INCLUDED
