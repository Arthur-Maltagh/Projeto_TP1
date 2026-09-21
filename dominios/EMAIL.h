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

/*
parte-local@domínio
Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-); não pode iniciar ou terminar
com ponto ou hífen; ponto ou hífen deve ser seguido por letra(s) ou dígito(s); comprimento
máximo é 64 caracteres.
Domínio é composto por uma ou mais partes separadas por ponto (.); cada parte pode conter letra
(a-z), dígito (0-9) ou hífen (-); não pode iniciar ou terminar com hífen; comprimento máximo é 255
caracteres.
*/
