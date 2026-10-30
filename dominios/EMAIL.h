/**
 * @file EMAIL.h
 * @brief Declara a classe domínios responsável pela representação de endereços
 * de e-mail.
 *
 */

#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include <string>

/**
 * @brief Representa um endereço de e-mail.
 *
 * A classe permite armazenar e consultar um endereço de e-mail,
 * respeitando as regras de formato definidas para o domínio EMAIL.
 *
 * O endereço é composto por uma parte local e um domínio, separados
 * pelo caractere '@'.
 *
 * A parte local aceita letras, dígitos, pontos e hífens, possui
 * comprimento máximo de 64 caracteres e não pode começar ou terminar
 * com ponto ou hífen. Cada ponto ou hífen deve ser seguido por letra
 * ou dígito.
 *
 * O domínio é composto por uma ou mais partes separadas por pontos.
 * Cada parte aceita letras, dígitos e hífens, não podendo começar
 * ou terminar com hífen. O comprimento máximo do domínio é de
 * 255 caracteres.
 */
class EMAIL {
private:
    std::string email;
    bool validar(std::string email);
    bool validarParteLocal(std::string parte_local);
    bool validarDominio(std::string dominio);
    static const int TAMANHO_MAX_LOCAL = 64;
    static const int TAMANHO_MAX_DOMINIO = 255;

public:

    /**
     * @brief Define o endereço de e-mail armazenado.
     *
     * Recebe um endereço de e-mail, verifica se seu formato é válido
     * e armazena o valor caso a validação seja bem-sucedida.
     *
     * @param email Endereço de e-mail a ser definido.
     * @throws std::invalid_argument Se o endereço apresentar formato
     * inválido.
     */
    void setEMAIL(std::string email);

    /**
     * @brief Consulta o endereço de e-mail armazenado.
     *
     * @return O endereço de e-mail atualmente armazenado.
     */
    std::string getEMAIL();
};

#endif // EMAIL_H_INCLUDED
