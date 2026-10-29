/**
 * @file Identificador.h
 * @brief classe domínio identificador que realiza a validação de um identificador de um usuário do sistema.
 * @author Arthur Rodrigues Malta
 * @date 2026
 */

#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED
#include <string>
using namespace std;

/**
 * @brief Domínio que representa um identificador de entidade.
 * @ingroup Dominios
 *
 * Regras do formato válido:
 * 1. possui exatamente 6 caracteres;
 * 2. os três primeiros caracteres são letras maiúsculas ou minúsculas;
 * 3. os três últimos caracteres são dígitos.
 *
 */
class Identificador{
private:
    string id;
    bool validar(string id);
    static const int TAMANHO_ID = 6;
public:
    /**
     * @brief Atribui um valor ao identificador.
     *
     * @param recebe uma string candidata a ser um id, caso seja válida.
     * @throw invalid_argument Se o formato de @p id for inválido.
     */
    void setIdentificador(string id);

    /**
     * @brief Retorna o identificador armazenado.
     *
     * @return string texto com formato válido.
     */
    string getIdentificador();
};

#endif // IDENTIFICADOR_H_INCLUDED
