#include "Limite.h"
#include <stdexcept>
using namespace std;

bool Limite::validar(int valor){
    if(valor < LIMITE_INF || valor > LIMITE_SUP)
        return false;
    return true;
}

int Limite::getLimite(){
    return limite;
}

void Limite::setLimite(int valor){
    if(!validar(valor))
        throw invalid_argument("Argumento invalido!");
    this -> limite = valor;
}
