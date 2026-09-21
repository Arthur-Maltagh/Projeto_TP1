#ifndef LIMITE_H_INCLUDED
#define LIMITE_H_INCLUDED
#include <stdexcept>
using namespace std;

class Limite{
private:
    static const int LIMITE_INF = 1;
    static const int LIMITE_SUP = 25;
    int limite;
    bool validar(int valor);
public:
    void setLimite(int valor);
    int getLimite();
};

#endif // LIMITE_H_INCLUDED
