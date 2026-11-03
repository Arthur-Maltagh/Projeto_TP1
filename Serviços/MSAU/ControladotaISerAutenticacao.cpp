#include "ControladoraIAprAutenticacao.h"
#include "ControladoraISerAutenticacao.h"
#include "ISerPessoa.h"
#include "Pessoa.h"

using namespace std;

bool CntrISerAutenticacao::autenticar(const EMAIL &email, const Senha &senha) {
    if (cntrISerPessoa == nullptr)
        return false;

    // Regra: a conta precisa existir...
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!cntrISerPessoa->ler(&pessoa))
        return false;

    // ...e a senha informada precisa ser igual a cadastrada.
    // Copias locais, pois os getters dos dominios nao sao const.
    Senha cadastrada = pessoa.getSenha();
    Senha informada = senha;
    return cadastrada.getSenha() == informada.getSenha();
}
