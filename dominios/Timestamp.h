/**
 * @file Timestamp.h
 * @brief Declaração da classe Timestamp.
 *
 * Contém a classe que representa o domínio Timestamp e valida
 * o formato dos valores atribuídos a ela.
 */

#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

#include <string>

/**
 * @brief Domínio que representa uma data e um horário.
 * @ingroup Dominios
 *
 * O formato válido é DIA-MES-ANO-HORARIO, com os componentes
 * separados por hífen.
 *
 * Regras do formato válido:
 *
 * 1. DIA é um número de 1 a 31, com um ou dois dígitos;
 * 2. MES é uma sigla entre JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO,
 *    SET, OUT, NOV e DEZ (letras maiúsculas);
 * 3. ANO é um número de 4 dígitos, de 2000 a 2099;
 * 4. HORARIO está no formato HH:MM, de 00:00 a 23:59;
 * 5. a data deve existir no calendário, considerando o número de dias
 *    de cada mês e os anos bissextos
 *
 */
class Timestamp{
private:
    std::string data;
    bool validar(std::string data);
    bool validar_dia(std::string dia);
    bool validar_mes(std::string mes);
    bool validar_ano(std::string ano);
    bool validar_horario(std::string horario);
    bool validar_dia_mes_bissexto(std::string dia,std::string mes,std::string ano);
    static const int TAMANHO_MAX = 17;
    static const int TAMANHO_SIGLA_MES = 3;
    static const int DIA_MIN = 1;
    static const int DIA_MAX = 31;
    static const int TAMANHO_ANO = 4;
    static const int ANO_MIN = 2000;
    static const int ANO_MAX = 2099;
    static const int TAMANHO_HORARIO = 5;
    static const int SEPARADOR = 2;
public:
    /**
     * @brief Atribui um valor ao timestamp.
     *
     * @param data Texto no formato DIA-MES-ANO-HORARIO
     * @throw std::invalid_argument Se o formato de @p data for inválido
     *        ou se a data não existir no calendário.
     */
    void setTimestamp(std::string data);

    /**
     * @brief Retorna o timestamp armazenado.
     *
     * @return Texto no formato DIA-MES-ANO-HORARIO.
     */
    std::string getTimestamp();
};

#endif // TIMESTAMP_H_INCLUDED
