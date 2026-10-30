#include "Prioridade.h" //Importa header file

void Prioridade::setPrioridade(string prioridade){
    validar(prioridade);
    this->prioridade = prioridade;
}

string Prioridade::getPrioridade() const{
    return prioridade;
}
// Método para validação de prioridade.
void Prioridade::validar(string prioridade) {
    if (prioridade != "ALTA" && prioridade != "MEDIA" && prioridade != "BAIXA")
        throw invalid_argument("Argumento invalido.");
}
