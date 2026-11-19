#ifndef CONTROLADORAIAPRPROJETO_H_INCLUDED
#define CONTROLADORAIAPRPROJETO_H_INCLUDED

/**
 * @file ControladoraIAprProjeto.h
 * @brief Declara a controladora de apresentação do módulo de projetos.
 */

#include "IAprProjeto.h"
#include "Projeto.h"

/**
 * @brief Realiza a interação com o usuário no módulo de projetos.
 *
 * A controladora consulta o papel da pessoa autenticada por ISerPessoa,
 * valida os dados de entrada usando as classes de domínio e solicita as
 * operações a ISerProjeto. A navegação para os quadros é delegada a IAprQuadro.
 */
class CntrIAprProjeto : public IAprProjeto {
private:
    ISerProjeto *cntrISerProjeto;
    ISerPessoa *cntrISerPessoa;
    IAprQuadro *cntrIAprQuadro;

    /** @brief Exibe os dados de um projeto. */
    void mostrarProjeto(Projeto &projeto);

    /** @brief Fluxo de criação de projeto para o gestor autenticado. */
    void criarProjeto(const EMAIL &gestor);

    /** @brief Fluxo de leitura de um projeto. */
    void lerProjeto();

    /** @brief Fluxo de atualização de um projeto existente. */
    void atualizarProjeto();

    /** @brief Recusa a exclusão quando o projeto possui quadros associados. */
    void excluirProjeto();

    /** @brief Lista os identificadores dos projetos. */
    void listarProjetos();

    /** @brief Abre o módulo de quadros para um projeto existente. */
    void abrirQuadros(const EMAIL &usuario);

public:
    /** @brief Constrói a controladora sem módulos associados. */
    CntrIAprProjeto()
        : cntrISerProjeto(nullptr), cntrISerPessoa(nullptr), cntrIAprQuadro(nullptr) {}

    /** @brief Executa o menu de projetos conforme o papel do usuário. */
    void executar(const EMAIL &email);

    /** @brief Conecta a implementação de ISerProjeto. */
    void setCntrISerProjeto(ISerProjeto *cntr) { cntrISerProjeto = cntr; }

    /** @brief Conecta a implementação de ISerPessoa para consultar o papel. */
    void setCntrISerPessoa(ISerPessoa *cntr) { cntrISerPessoa = cntr; }

    /** @brief Conecta a apresentação de quadros acessada a partir do projeto. */
    void setCntrIAprQuadro(IAprQuadro *cntr) { cntrIAprQuadro = cntr; }
};

#endif // CONTROLADORAIAPRPROJETO_H_INCLUDED
