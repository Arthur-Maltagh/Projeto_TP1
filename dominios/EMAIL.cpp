#include "EMAIL.h"
#include <cctype>
#include <stdexcept>

bool EMAIL::validar(string email){

    if(email.empty())
        return false;

    size_t posicao_arroba = email.find('@');
    if(posicao_arroba == string::npos)
        return false;

    string parte_local = email.substr(0, posicao_arroba);
    string dominio = email.substr(posicao_arroba + 1);

    if(parte_local.empty() || dominio.empty())
        return false;
    if(!validarParteLocal(parte_local))
        return false;
    if(!validarDominio(dominio))
        return false;

    return true;
}

void EMAIL::setEMAIL(string email){
    if(!validar(email))
        throw invalid_argument("Argumento invalido");
    this -> email = email;
}

string EMAIL::getEMAIL(){
    return email;
}


//função de validação da parte local
bool EMAIL::validarParteLocal(string parte_local) {
    if(parte_local.length() > TAMANHO_MAX_LOCAL){
        return false;
    }

    //verificando as condições do início e final da parte-local
    if(parte_local[0] == '.' || parte_local[0] == '-')
        return false;
    if(parte_local[parte_local.length() - 1] == '.' || parte_local[parte_local.length() - 1] == '-')
        return false;


    //analisando cada posicao para verificar se segue as condicoes propostas
    for(int i = 0;i < parte_local.length();i++){
        if(!isalnum(parte_local[i]) && parte_local[i] != '-' && parte_local[i] != '.')
            return false;

        if(isalpha(parte_local[i]) && !islower(parte_local[i]))
            return false;

        if(parte_local[i] == '-' || parte_local[i] == '.'){
            if(i + 1 >= parte_local.length() || !isalnum(parte_local[i + 1]))
                return false;
        }
    }
    return true;
}


//função de validação de dominios
bool EMAIL::validarDominio(string dominio) {
    if (dominio.length() > TAMANHO_MAX_DOMINIO) {
        return false;
    }

     //verificando as condicoes do inicio e final do dominio
    if(dominio[0] == '-')
        return false;
    if(dominio[dominio.length() - 1] == '-')
        return false;


    //analisando os caracteres de dominio
    for(int i = 0;i < dominio.length();i++){

        if(!isalnum(dominio[i]) && dominio[i] != '-' && dominio[i] != '.')
            return false;

        if(isalpha(dominio[i]) && !islower(dominio[i]))
            return false;

       if(dominio[i] == '-' || dominio[i] == '.'){
            if(i + 1 < dominio.length()){
                if(!isalnum(dominio[i + 1]))
                    return false;
                }
            }
    }

    return true;
}


/*parte-local@domínio
Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-); não pode iniciar ou terminar
com ponto ou hífen; ponto ou hífen deve ser seguido por letra(s) ou dígito(s); comprimento
máximo é 64 caracteres.

Domínio é composto por uma ou mais partes separadas por ponto (.); cada parte pode conter letra
(a-z), dígito (0-9) ou hífen (-); não pode iniciar ou terminar com hífen; comprimento máximo é 255
caracteres.
*/
