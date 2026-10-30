#include "Papel.h"
using namespace std;


void Papel::setPapel(string papel){
    validar(papel);
    this->papel = papel;
}

string Papel::getPapel() const{
    return papel;
}

// Método para validação de Papel.
void Papel::validar(string papel) {
    if (papel != "GESTOR" && papel != "DESENVOLVEDOR")
        throw invalid_argument("Argumento invalido.");
}
