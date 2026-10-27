#include "Teste_Prioridade.h" //Importa header file

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade.

const std::string Teste_Prioridade::PRIORIDADE_VALIDO = "MEDIA";
const std::string Teste_Prioridade::PRIORIDADE_INVALIDO = "NENHUMA";

void Teste_Prioridade::construtor(){
    prioridade = new Prioridade();
    estado_do_teste = SUCESSO;
}

void Teste_Prioridade::destrutor(){
    delete prioridade;
}

void Teste_Prioridade::testarCenarioSucesso(){
    try{
        prioridade->setPrioridade(PRIORIDADE_VALIDO);
        if (prioridade->getPrioridade() != PRIORIDADE_VALIDO)
            estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
        estado_do_teste = FALHA;
    }
}

void Teste_Prioridade::testarCenarioFalha(){
    try{
        prioridade->setPrioridade(PRIORIDADE_INVALIDO);
        estado_do_teste = FALHA;
    }
    catch(invalid_argument &excecao){
    }
}

int Teste_Prioridade::run(){
    construtor();
    testarCenarioSucesso();
    testarCenarioFalha();
    destrutor();
    return estado_do_teste;
}
