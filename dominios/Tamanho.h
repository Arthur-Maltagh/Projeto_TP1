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

using namespace std;

/**
 * @class Tamanho
 * @brief Classe que representa o tamanho.
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
        string tamanho;
        // Método para validar tamanho.
        void validar(string);
    public:
         // Método para atribuir tamanho.
        void setTamanho(string tamanho);
        // Método para recuperar tamanho.
        string getTamanho() const;
};

inline void Tamanho::setTamanho(string tamanho){
    validar(tamanho);
    this->tamanho = tamanho;
}

inline string Tamanho::getTamanho() const{
    return tamanho;
}



#endif // TAMANHO_H_INCLUDED
