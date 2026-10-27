#ifndef TESTE_TAMANHO_H_INCLUDED
#define TESTE_TAMANHO_H_INCLUDED

// Incluir cabeçalhos.
#include <string>
#include "../../dominios/Tamanho.h" //Importa header file

using namespace std;

// --------------------------------------------------------------------------
// Exemplo de declaração de classe para teste de unidade de classe domínio.

class Teste_Tamanho {
private:
    const static std::string TAMANHO_VALIDO;   // Definição de constante para evitar número mágico.
    const static std::string TAMANHO_INVALIDO;   // Definição de constante para evitar número mágico.
    Tamanho *tamanho;                         // Referência para unidade em teste.
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

#endif // TESTE_TAMANHO_H_INCLUDED
