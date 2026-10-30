/**
 * @file estado.h
 * @brief Armazenar e informar estado.
 * @author Maria Eduarda Santana Rodrigues
 * @date 2026
 */


#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED

#include <stdexcept>
#include <string>

/**
 * @class Estado
 * @brief Classe que representa o estado.
* @ingroup Dominios
 * ESTADO (definição): condição em que um objeto ou tarefa se encontra.
 * Formato válido: A FAZER, FAZENDO, FEITO.
 * Métodos:
 * - setEstado()
 * @brief Método que atribui um valor a estado.
 * @param[in] papel: valor que será atribuído a estado.
 * @throw std::invalid_argument caso o valor informado tenha formato inválido.
 * - getEstado()
 * @brief Método que retorna o valor atribuído a estado.
 * @return valor de estado válido e atualmente armazenado.
 */

class Estado {
    private:
        // Atributo para armazenar estado.
        std::string estado;
        // Método para validar estado.
        void validar(std::string);
    public:
         // Método para atribuir estado.
        void setEstado(std::string estado);
        // Método para recuperar estado.
        std::string getEstado() const;
};




#endif // ESTADO_H_INCLUDED
