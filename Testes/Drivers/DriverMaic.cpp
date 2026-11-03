#include "DriverMAIC.h"

#include "ControladoraIAprAutenticacao.h"
#include "ControladoraIAprPessoa.h"
#include "ControladoraIAprPrincipal.h"
#include "ControladoraISerAutenticacao.h"
#include "ControladoraISerPessoa.h"
#include "StubIAprProjeto.h"

int executarDriverMAIC() {
    // Camada de servico (reais)
    CntrISerPessoa serPessoa;
    CntrISerAutenticacao serAutenticacao;
    serAutenticacao.setCntrISerPessoa(&serPessoa);

    // Camada de apresentacao (reais, exceto projetos)
    CntrIAprAutenticacao aprAutenticacao;
    aprAutenticacao.setCntrISerAutenticacao(&serAutenticacao);

    CntrIAprPessoa aprPessoa;
    aprPessoa.setCntrISerPessoa(&serPessoa);

    StubIAprProjeto aprProjeto;     // modulo de outro integrante

    // Modulo principal
    CntrIAprPrincipal maic;
    maic.setCntrIAprAutenticacao(&aprAutenticacao);
    maic.setCntrIAprPessoa(&aprPessoa);
    maic.setCntrIAprProjeto(&aprProjeto);

    maic.executar();
    return 0;
}
