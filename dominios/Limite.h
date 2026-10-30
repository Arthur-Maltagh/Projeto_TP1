/**
 * @file Limite.h
 * @brief Declaração da classe de domínio Limite.
 * @author Arthur Rodrigues Malta
 * @date 2026
 */

#ifndef LIMITE_H_INCLUDED
#define LIMITE_H_INCLUDED
#include <stdexcept>

/**
 * @brief Domínio que representa o limite de WIP de um quadro
 * e Designa o número máximo de atividades simultâneas na coluna FAZENDO.
 *
 * Regra do valor válido:
 * 1. número inteiro de 1 a 25.
 */
class Limite{
private:
    static const int LIMITE_INF = 1;
    static const int LIMITE_SUP = 25;
    int limite;
    bool validar(int valor);
public:
    /**
     * @brief Atribui um valor ao limite.
      * @ingroup Dominios
     *
     * @param valor Número inteiro entre 1 e 25.
     * @throw invalid_argument Se @p valor estiver fora do intervalo de 1 a 25.
     */
    void setLimite(int valor);

    /**
     * @brief Retorna o limite armazenado.
     *
     * @return Número inteiro válido.
     *
     */
    int getLimite();
};

#endif // LIMITE_H_INCLUDED
