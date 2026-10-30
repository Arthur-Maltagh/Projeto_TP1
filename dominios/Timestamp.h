#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

#include <string>

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
    void setTimestamp(std::string data);
    std::string getTimestamp();
};


#endif // TIMESTAMP_H_INCLUDED

