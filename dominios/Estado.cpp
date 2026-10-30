#include "Estado.h"

void Estado::setEstado(string estado){
    validar(estado);
    this->estado = estado;
}

string Estado::getEstado() const{
    return estado;
}

void Estado::validar(string estado) {
    if (estado != "A FAZER" && estado != "FAZENDO" && estado != "FEITO")
        throw invalid_argument("Argumento invalido.");
}
