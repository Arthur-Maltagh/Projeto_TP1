#ifndef TESTE_ESTADO_H_INCLUDED
#define TESTE_ESTADO_H_INCLUDED

#include "../../dominios/Estado.h"

using namespace std;

// --------------------------------------------------------------------------
// Exemplo de declaração de classe para teste de unidade de classe domínio.

class Teste_Estado {
private:
    const static std::string ESTADO_VALIDO;   // Definição de constante para evitar número mágico.
    const static std::string ESTADO_INVALIDO;   // Definição de constante para evitar número mágico.
    Estado *estado;                         // Referência para unidade em teste.
    int estado_do_teste;                             // Estado do teste.
    void construtor();                           // Método para criar unidade em teste.
    void destrutor();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

#endif // TESTE_ESTADO_H_INCLUDED
