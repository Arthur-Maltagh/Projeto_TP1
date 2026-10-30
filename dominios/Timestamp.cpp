#include "Timestamp.h"
#include <cctype>
#include <stdexcept>
using namespace std;

bool Timestamp::validar(string data){
    string data_separada[4];
    if(data.empty())
        return false;
    if(data.length() > TAMANHO_MAX)
        return false;

    int componente = 0;
    int qnt_hifens = 0;
    int pos = 0;
    string aux;

   for(size_t i = 0; i < data.length();i++){
        if(data[i] == '-'){
            qnt_hifens++;
            data_separada[componente] = aux;
            aux.clear();
            componente++;
        }else{
            aux += data[i];
        }
        if(qnt_hifens == 3){
            pos = i;
            break;
        }
    }

    if(qnt_hifens != 3)
        return false;

    data_separada[3] = data.substr(pos + 1);

    string dia,mes,ano,horario;
    dia = data_separada[0];
    mes = data_separada[1];
    ano = data_separada[2];
    horario = data_separada[3];
    if(!validar_dia_mes_bissexto(dia,mes,ano))
        return false;
    if(!validar_horario(horario))
        return false;

    return true;
}


void Timestamp::setTimestamp(string data){
    if(!validar(data))
        throw invalid_argument("Argumento inválido");
    this -> data = data;
}

string Timestamp::getTimestamp(){
    return data;
}

bool Timestamp::validar_dia(string dia_txt){
    int dia;
    if(dia_txt.empty())
        return false;
    if(dia_txt.length() > 2)
        return false;
    for(size_t i = 0;i < dia_txt.length();i++){
        if(!isdigit(static_cast<unsigned char>(dia_txt[i])))
            return false;
    }
    dia = stoi(dia_txt);
    if(dia > DIA_MAX or dia < DIA_MIN)
        return false;

    return true;
}

bool Timestamp::validar_mes(string mes){
    if(mes.length() != TAMANHO_SIGLA_MES)
        return false;

    if(mes != "JAN" && mes != "FEV" && mes != "MAR" && mes != "ABR" && mes != "MAI" && mes != "JUN" && mes != "JUL"
    && mes != "AGO" && mes != "SET" && mes != "OUT" && mes != "NOV" && mes != "DEZ"){
              return false;
    }
    return true;
}

bool Timestamp::validar_ano(string ano_txt){
    int ano;
    if(ano_txt.length() != TAMANHO_ANO)
        return false;
    for(int i = 0;i < TAMANHO_ANO;i++){
        if(!isdigit(ano_txt[i]))
            return false;
    }
    ano = stoi(ano_txt);
    if(ano < ANO_MIN or ano > ANO_MAX)
        return false;

    return true;
}

bool Timestamp::validar_horario(string horario){
    int horas,minutos;
    if(horario.empty())
        return false;
    if(horario.length() != TAMANHO_HORARIO)
        return false;
    if(horario[SEPARADOR] != ':')
        return false;

    for(int i = 0; i < TAMANHO_HORARIO;i++){
        if(i != SEPARADOR){
            if(!isdigit(horario[i]))
                return false;
        }
    }
    horas = stoi(horario.substr(0,SEPARADOR));
    minutos = stoi(horario.substr(SEPARADOR + 1));
    if(horas > 23 || minutos > 59)
        return false;

    return true;

}

bool Timestamp::validar_dia_mes_bissexto(string dia_txt, string mes,string ano_txt){
    if(!validar_dia(dia_txt))
        return false;
    if(!validar_mes(mes))
        return false;
    if(!validar_ano(ano_txt))
        return false;
    int dia,ano;

    dia = stoi(dia_txt);
    ano = stoi(ano_txt);

    if(mes == "ABR" && dia > 30)
        return false;

    if(mes == "JUN" && dia > 30)
        return false;

    if(mes == "SET" && dia > 30)
        return false;

    if(mes == "NOV" && dia > 30)
        return false;

    bool bissexto = (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0));

    if(mes == "FEV"){
        if(bissexto && dia > 29)
        return false;

        if(!bissexto && dia > 28)
            return false;
     }

    return true;
}
/*DIA-MÊS-ANO-HORÁRIO
DIA é número 1 a 31.
MÊS é sigla JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
ANO é número de 2000 a 2099.
HORÁRIO é valor de 00:00 a 23:59
A data deve ser válida considerando anos bissextos.
*/

//12-JAN-2017-20:21
