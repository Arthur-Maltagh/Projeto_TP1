#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED
#include <string>
using namespace std;

class EMAIL{
private:
    string email;
    bool validar(string email);
    bool validarParteLocal(string parte_local);
    bool validarDominio(string dominio);
    static const int TAMANHO_MAX_LOCAL = 64;
    static const int TAMANHO_MAX_DOMINIO = 255;
public:
    void setEMAIL(string email);
    string getEMAIL();
};

#endif // EMAIL_H_INCLUDED
