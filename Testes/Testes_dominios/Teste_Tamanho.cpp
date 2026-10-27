#include "Teste_Tamanho.h" //Importa header file

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade.

const std::string Teste_Tamanho::TAMANHO_VALIDO = "GRANDE";
const std::string Teste_Tamanho::TAMANHO_INVALIDO = "SUFICIENTE";

void Teste_Tamanho::construtor(){
    tamanho = new Tamanho();
    estado_do_teste = SUCESSO;
}

void Teste_Tamanho::destrutor(){
    delete tamanho;
}

void Teste_Tamanho::testarCenarioSucesso(){
    try{
        tamanho->setTamanho(TAMANHO_VALIDO);
        if (tamanho->getTamanho() != TAMANHO_VALIDO)
            estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
        estado_do_teste = FALHA;
    }
}

void Teste_Tamanho::testarCenarioFalha(){
    try{
        tamanho->setTamanho(TAMANHO_INVALIDO);
        estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
    }
}

int Teste_Tamanho::run(){
    construtor();
    testarCenarioSucesso();
    testarCenarioFalha();
    destrutor();
    return estado_do_teste;
}
