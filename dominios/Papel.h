/**
 * @file papel.h
 * @brief Armazenar e informar papel.
 * @author Maria Eduarda Santana Rodrigues
 * @date 2026
 */

#ifndef PAPEL_H_INCLUDED
#define PAPEL_H_INCLUDED

#include <stdexcept>
#include <string>

using namespace std;

/**
 * @class Papel
 * @brief Classe que representa o papel.
* @ingroup Dominios
 * PAPEL (definição): conjunto de funções, expectativas, deveres e comportamentos que um sujeito deve desempenhar em uma determinada situação.
 * Formato válido: GESTOR, DESENVOLVEDOR.
 * Métodos:
 * - setPapel()
 * @brief Método que atribui um valor a papel.
 * @param[in] papel: valor que será atribuído a papel.
 * @throw std::invalid_argument caso o valor informado tenha formato inválido.
 * - getPapel()
 * @brief Método que retorna o valor atribuído a papel.
 * @return valor de papel válido e atualmente armazenado.
 */

class Papel {
    private:
        // Atributo para armazenar papel.
        string papel;
        // Método para validar papel.
        void validar(string);
    public:
         // Método para atribuir papel.
        void setPapel(string papel);
        // Método para recuperar papel.
        string getPapel() const;
};

#endif // PAPEL_H_INCLUDED
