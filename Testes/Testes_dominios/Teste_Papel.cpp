#include "Teste_Papel.h" //Importa header file

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade.

const std::string Teste_Papel::PAPEL_VALIDO = "DESENVOLVEDOR";
const std::string Teste_Papel::PAPEL_INVALIDO = "CLIENTE";

void Teste_Papel::construtor(){
    papel = new Papel();
    estado_do_teste = SUCESSO;
}

void Teste_Papel::destrutor(){
    delete papel;
}

void Teste_Papel::testarCenarioSucesso(){
    try{
        papel->setPapel(PAPEL_VALIDO);
        if (papel->getPapel() != PAPEL_VALIDO)
            estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
        estado_do_teste = FALHA;
    }
}

void Teste_Papel::testarCenarioFalha(){
    try{
        papel->setPapel(PAPEL_INVALIDO);
        estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
    }
}

int Teste_Papel::run(){
    construtor();
    testarCenarioSucesso();
    testarCenarioFalha();
    destrutor();
    return estado_do_teste;
}
