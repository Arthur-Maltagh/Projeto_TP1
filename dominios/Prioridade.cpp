#include "Prioridade.h" //Importa header file

// Método para validação de prioridade.
void Prioridade::validar(string prioridade) {
    if (prioridade != "ALTA" && prioridade != "MEDIA" && prioridade != "BAIXA")
        throw invalid_argument("Argumento invalido.");
}
