/**
 * @file Nome.h
 * @brief Declaração da classe de domínio Nome.
 * @author Arthur Rodrigues Malta
 * @date 2026
 */

#ifndef NOME_H_INCLUDED
#define NOME_H_INCLUDED
#include <string>
using namespace std;

/**
 * @brief Domínio que responsável por valdiar e armazenar nome de um usuário do sistema.
 * @ingroup Dominios
 *
 * Regras do formato válido:
 * 1. texto com até 15 caracteres, não vazio;
 * 2. cada caractere é letra maiúscula, letra minúscula ou espaço em branco;
 * 3. o primeiro e o último caractere não são espaço em branco;
 * 4. todo espaço em branco é seguido por uma letra.
 * 5. acentos não são considerados
 *
 *
 */
class Nome{
private:
    string nome;
    bool validar(string nome);
public:
    /**
     * @brief Atribui um valor ao nome.
     *
     * @param string será validada pelas condições de formato válido
     * @throw invalid_argument Se o formato de @p nome for inválido.
     */
    void setNome(string nome);

    /**
     * @brief Retorna o nome armazenado.
     *
     * @return Texto com o nome, de até 15 caracteres.
     */
    string getNome();
};

#endif // NOME_H_INCLUDED
