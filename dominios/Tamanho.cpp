#include "Tamanho.h" //Importa header file

// Método para validação de Tamanho.
void Tamanho::validar(string tamanho) {
    if (tamanho != "GRANDE" && tamanho != "MÉDIO" && tamanho != "PEQUENO")
        throw invalid_argument("Argumento invalido.");
}
