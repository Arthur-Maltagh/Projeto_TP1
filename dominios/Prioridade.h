/**
 * @file prioridade.h
 * @brief Armazenar e informar prioridade.
 * @author Maria Eduarda Santana Rodrigues
 * @date 2026
 */

#ifndef PRIORIDADE_H_INCLUDED
#define PRIORIDADE_H_INCLUDED

#include <stdexcept>
#include <string>

/**
 * @class Prioridade
 * @brief Classe que representa a prioridade.
 * @ingroup Dominios
 * PRIORIDADE (definição): a condição daquilo que ocupa o primeiro lugar em importância, urgência, necessidade ou ordem temporal.
 * Formato válido: ALTA, MÉDIA e BAIXA.
 * Métodos:
 * - setPrioridade()
 * @brief Método que atribui um valor a prioridade.
 * @param[in] valor que será atribuído a prioridade.
 * @throw std::invalid_argument caso o valor informado tenha formato inválido.
 * - getPrioridade()
 * @brief Método que retorna o  valor atribuído a prioridade.
 * @return valor de prioridade válido e atualmente armazenado.
 */
class Prioridade {
    private:
        // Atributo para armazenar prioridade.
        std::string prioridade;
        // Método para validar prioridade.
        void validar(std::string);
    public:
         // Método para atribuir prioridade.
        void setPrioridade(std::string prioridade);
        // Método para recuperar prioridade.
        std::string getPrioridade() const;
};

#endif // PRIORIDADE_H_INCLUDED
