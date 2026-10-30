/**
 * @file Texto.h
 * @brief Declaração da classe de domínio Texto.
 * @author Arthur Rodrigues Malta
 * @date 2026
 */

#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED
#include <string>

/**
 * @brief Domínio que representa e valida um texto, como uma descrição.
 * @ingroup Dominios
 *
 * Regras do formato válido:
 * 1. texto não vazio com até 30 caracteres;
 * 2. cada caractere pode ser letra, dígito, espaço em branco
 * ou sinal de pontuação (vírgula, ponto e vírgula, ponto, dois pontos,
 * ponto de interrogação ou ponto de exclamação);
 * 3. um sinal de pontuação não é seguido por outro sinal de pontuação;
 * 4. o primeiro caractere é letra maiúscula;
 * 5. o último caractere é ponto.
 *
 */
class Texto{
private:
    std::string texto;
    bool validar(std::string texto);
    static const int TAMANHO_MAX = 30;
public:
    /**
     * @brief Atribui um valor ao texto.
     *
     * @param string que será um texto que será submetido a validação
     * @throw invalid_argument Se o formato de @p texto for inválido.
     */
    void setTexto(std::string texto);

    /**
     * @brief Retorna o texto armazenado.
     *
     * @return string validada.
     */
    std::string getTexto();
};

#endif // TEXTO_H_INCLUDED
