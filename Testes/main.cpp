#include <iostream>
using namespace std;
bool teste_Limite();
bool teste_Nome();
bool teste_Senha();
bool teste_Texto();
bool teste_Identificador();
bool teste_Email();
bool teste_Pessoa();

int main() {

    if (teste_Limite()) {
        cout << "Teste do Dominio Limite: Aprovado" << endl;
    } else {
        cout << "Teste do Dominio Limite: Falhou" << endl;
    }

     if (teste_Nome()) {
        cout << "Teste do Dominio nome: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio nome: Falhou!" << endl;
    }


     if (teste_Senha()) {
        cout << "Teste do Dominio Senha: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Senha: Falhou!" << endl;
    }

    if (teste_Texto()) {
        cout << "Teste do Dominio Texto: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Texto: Falhou!" << endl;
    }

    if (teste_Identificador()) {
        cout << "Teste do Dominio Identificador: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio Identificador: Falhou!" << endl;
    }

    if(teste_Email()){
        cout << "Teste do Dominio EMAIL: Aprovado!" << endl;
    } else {
        cout << "Teste do Dominio EMAIL: Falhou!" << endl;
    }

    //teste das entidades
    if(teste_Pessoa()){
        cout << "Teste da Entidade Pessoa: Aprovado!" << endl;
    } else {
        cout << "Teste da Entidade Pessoa: Falhou!" << endl;
    }



    cout << "\nPressione ENTER para sair...";
    cin.get();

    return 0;
}
