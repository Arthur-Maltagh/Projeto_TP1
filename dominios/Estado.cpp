#include "Estado.h"

void Estado::validar(string estado) {
    if (estado != "A FAZER" && estado != "FAZENDO" && estado != "FEITO")
        throw invalid_argument("Argumento invalido.");
}
