#include "StubSerAutenticacao.h"

using namespace std;

bool StubISerAutenticacao::autenticar(const EMAIL &email, const Senha &senha) {
    // Copias locais, pois os getters dos dominios nao sao const.
    EMAIL e = email;
    Senha s = senha;
    return e.getEMAIL() == "ana@teste.com" && s.getSenha() == "abc12";
}
