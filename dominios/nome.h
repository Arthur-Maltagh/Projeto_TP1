#ifndef NOME_H_INCLUDED
#define NOME_H_INCLUDED
#include <string>
using namespace std;

class Nome{
private:
    string nome;
    bool validar(string nome);
public:
    void setNome(string nome);
    string getNome();
};

#endif // NOME_H_INCLUDED
