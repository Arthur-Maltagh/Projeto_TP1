#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED
#include <string>
using namespace std;

class Senha{
private:
    string senha;
    bool validar(string senha);
    static const int TAMANHO_SENHA = 5;
public:
    void setSenha(string senha);
    string getSenha();
};


#endif // SENHA_H_INCLUDED
