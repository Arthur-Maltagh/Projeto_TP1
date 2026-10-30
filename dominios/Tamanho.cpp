#include "Tamanho.h" //Importa header file
using namespace std;

void Tamanho::setTamanho(string tamanho){
    validar(tamanho);
    this->tamanho = tamanho;
}

string Tamanho::getTamanho() const{
    return tamanho;
}
// Método para validação de Tamanho.
void Tamanho::validar(string tamanho) {
    if (tamanho != "GRANDE" && tamanho != "MÉDIO" && tamanho != "PEQUENO")
        throw invalid_argument("Argumento invalido.");
}
