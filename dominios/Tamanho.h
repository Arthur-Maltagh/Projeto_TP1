/**
 * @file tamanho.h
 * @brief Armazenar e informar tamanho.
 * @author Maria Eduarda Santana Rodrigues
 * @date 2026
 */

#ifndef TAMANHO_H_INCLUDED
#define TAMANHO_H_INCLUDED

#include <stdexcept>
#include <string>


/**
 * @class Tamanho
 * @brief Classe que representa o tamanho.
 * @ingroup Dominios
 * TAMANHO (definição): grandeza, volume, área, dimensões de um corpo, objeto ou  tarefa.
 * Formato válido: GRANDE, MÉDIO, PEQUENO.
 * Métodos:
 * - setTamanho()
 * @brief Método que atribui um valor a tamanho.
 * @param[in] valor que será atribuído a tamanho.
 * @throw std::invalid_argument caso o valor informado tenha formato inválido.
 * - getTamanho()
 * @brief Método que retorna o  valor atribuído a tamanho.
 * @return valor de tamanho válido e atualmente armazenado.
 */

class Tamanho {
    private:
        // Atributo para armazenar tamanho.
        std::string tamanho;
        // Método para validar tamanho.
        void validar(std::string);
    public:
         // Método para atribuir tamanho.
        void setTamanho(std::string tamanho);
        // Método para recuperar tamanho.
        std::string getTamanho() const;
};





#endif // TAMANHO_H_INCLUDED
