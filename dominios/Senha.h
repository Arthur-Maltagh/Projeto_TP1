/**
 * @file Senha.h
 * @brief Declaração da classe de domínio Senha.
 * @author Arthur Rodrigues Malta
 * @date 2026
 */

#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED
#include <string>

/**
 * @brief Domínio que armazena e valida a senha de um usuário.
 * @ingroup Dominios
 *
 * Regras do formato válido:
 * 1. deve ser composta por 5 caracteres;
 * 2. cada caractere deve ser alfanumérico;
 * 3. deve ter pelo menos uma letra e um dígito.
 *
 */
class Senha{
private:
    std::string senha;
    bool validar(std::string senha);
    static const int TAMANHO_SENHA = 5;
public:
    /**
     * @brief Atribui um valor à senha.
     *
     * @param string que passará pela validação
     * @throw invalid_argument Se o formato de @p senha for inválido.
     */
    void setSenha(std::string senha);

    /**
     * @brief Retorna a senha armazenada.
     * @return string senha validada.
     */
    std::string getSenha();
};

#endif // SENHA_H_INCLUDED
