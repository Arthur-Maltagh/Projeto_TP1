#include <iostream>
#include "Testes_dominios/Teste_limite.h"
#include "Testes_dominios/teste_Senha.h"
#include "Testes_dominios/Teste_Nome.h"
#include "Testes_dominios/Teste_Texto.h"
#include "Testes_dominios/Teste_Identificador.h"
#include "Testes_dominios/Teste_EMAIL.h"
#include "Teste_entidades/Teste_Pessoa.h"


using namespace std;

Teste_Limite limite;
Teste_Senha senha;
Teste_Nome nome;
Teste_Texto texto;
Teste_Identificador identificador;
Teste_EMAIL Email;
Teste_Pessoa pessoa;

int main() {

    //teste dominios
    if (limite.run() == 0) {
        cout << "Teste do Dominio Limite: Aprovado" << endl;
    } else {
        cout << "Teste do Dominio Limite: Falhou" << endl;
    }

     if (nome.run() == 0) {
        cout << "Teste do Dominio Nome: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Nome: Falhou!" << endl;
    }


     if (senha.run() == 0) {
        cout << "Teste do Dominio Senha: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Senha: Falhou!" << endl;
    }

    if (texto.run() == 0) {
        cout << "Teste do Dominio Texto: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Texto: Falhou!" << endl;
    }

    if (identificador.run() == 0) {
        cout << "Teste do Dominio Identificador: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Identificador: Falhou!" << endl;
    }

    if(Email.run() == 0){
        cout << "Teste do Dominio EMAIL: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio EMAIL: Falhou!" << endl;
    }

    //teste das entidades
    if(pessoa.run() == 0){
        cout << "Teste da Entidade Pessoa: Aprovado!" << endl;
    } else {
        cout << "Teste da Entidade Pessoa: Falhou!" << endl;
    }



    cout << "\nPressione ENTER para sair...";
    cin.get();

    return 0;
}
