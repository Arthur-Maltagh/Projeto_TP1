#include "Papel.h"

// Método para validação de Papel.
void Papel::validar(string papel) {
    if (papel != "GESTOR" && papel != "DESENVOLVEDOR")
        throw invalid_argument("Argumento invalido.");
}
