/**
 * @file ISerCartao.h
 * @brief Declaração da interface de serviço de cartões de atividade.
 */

#ifndef ISERCARTAO_H_INCLUDED
#define ISERCARTAO_H_INCLUDED


#include <list>

#include "CartaoAtividades.h"
#include "EMAIL.h"
#include "Estado.h"
#include "Identificador.h"

/**
 * @brief Interface de serviço de cartões de atividade.
 * @ingroup Interfaces
 *
 * Provida pelo módulo MSQU. Corresponde aos serviços 16 a 26 da
 * especificação. Todos os métodos retornam false quando o serviço
 * não pôde ser realizado. Durações são expressas em minutos.
 */
class ISerCartao {
public:
    /**
     * @brief Cria um cartão em um quadro.
     *
     * O serviço define estado A FAZER e registra o instante de entrada.
     * Os demais campos de tempo ficam sem valor.
     *
     * @param cartao Dados do novo cartão.
     * @param quadro Identificador do quadro ao qual o cartão pertence.
     * @param desenvolvedor Email da pessoa responsável pelo cartão.
     * @return false se já existe cartão com o mesmo identificador ou se
     *         o quadro não existe.
     */
    virtual bool criar(const CartaoDeAtividade &cartao,
                       const Identificador &quadro,
                       const EMAIL &desenvolvedor) = 0;

    /**
     * @brief Lê os dados de um cartão.
     * @param cartao Na entrada, contém o identificador do cartão.
     *        Na saída, contém todos os dados do cartão.
     * @return false se o cartão não existe.
     */
    virtual bool ler(CartaoDeAtividade *cartao) = 0;

    /**
     * @brief Atualiza os dados de um cartão.
     *
     * O identificador não pode ser alterado. Estado e tempos só mudam
     * por meio de mover().
     *
     * @param cartao Novos dados, com o identificador do cartão.
     * @return false se o cartão não existe.
     */
    virtual bool atualizar(const CartaoDeAtividade &cartao) = 0;

    /**
     * @brief Exclui um cartão.
     * @param cartao Identificador do cartão a excluir.
     * @return false se o cartão não existe.
     */
    virtual bool excluir(const Identificador &cartao) = 0;

    /**
     * @brief Lista os identificadores dos cartões de um quadro.
     * @param quadro Identificador do quadro.
     * @param cartoes Recebe os identificadores dos cartões do quadro.
     * @return true se a listagem foi realizada.
     */
    virtual bool listar(const Identificador &quadro,
                        std::list<Identificador> *cartoes) = 0;

    /**
     * @brief Move um cartão para a coluna seguinte do quadro.
     *
     * Movimentos permitidos: A FAZER para FAZENDO e FAZENDO para FEITO.
     * Ao entrar em FAZENDO registra o início; ao entrar em FEITO,
     * registra o término.
     *
     * @param cartao Identificador do cartão.
     * @param destino Coluna de destino.
     * @return false se o cartão não existe, se o movimento não é
     *         permitido ou se o destino é FAZENDO e o quadro já atingiu
     *         o limite de WIP.
     */
    virtual bool mover(const Identificador &cartao, const Estado &destino) = 0;

    /**
     * @brief Lê o tempo de ciclo de um cartão.
     *
     * Tempo entre a entrada em FAZENDO e a chegada em FEITO.
     *
     * @param cartao Identificador do cartão.
     * @param minutos Recebe o tempo de ciclo, em minutos.
     * @return false se o cartão não existe ou ainda não foi concluído.
     */
    virtual bool lerTempoCiclo(const Identificador &cartao, int *minutos) = 0;

    /**
     * @brief Lê o tempo de ciclo médio dos cartões concluídos de um quadro.
     * @param quadro Identificador do quadro.
     * @param minutos Recebe a média, em minutos.
     * @return false se o quadro não existe ou não possui cartões concluídos.
     */
    virtual bool lerTempoCicloMedio(const Identificador &quadro,
                                    double *minutos) = 0;

    /**
     * @brief Lê o lead time de um cartão.
     *
     * Tempo entre a entrada em A FAZER e a chegada em FEITO.
     *
     * @param cartao Identificador do cartão.
     * @param minutos Recebe o lead time, em minutos.
     * @return false se o cartão não existe ou ainda não foi concluído.
     */
    virtual bool lerLeadTime(const Identificador &cartao, int *minutos) = 0;

    /**
     * @brief Lê o lead time médio dos cartões concluídos de um quadro.
     * @param quadro Identificador do quadro.
     * @param minutos Recebe a média, em minutos.
     * @return false se o quadro não existe ou não possui cartões concluídos.
     */
    virtual bool lerLeadTimeMedio(const Identificador &quadro,
                                  double *minutos) = 0;

    /**
     * @brief Lê o WIP de um quadro.
     *
     * Número de cartões na coluna FAZENDO.
     *
     * @param quadro Identificador do quadro.
     * @param wip Recebe o número de cartões em FAZENDO.
     * @return false se o quadro não existe.
     */
    virtual bool lerWIP(const Identificador &quadro, int *wip) = 0;

    /**
     * @brief Informa se uma pessoa é desenvolvedora de algum cartão.
     * @param desenvolvedor Email da pessoa consultada.
     * @return true se existe ao menos um cartão sob responsabilidade
     *         da pessoa.
     */
    virtual bool possuiCartoes(const EMAIL &desenvolvedor) = 0;

    /** @brief Destrutor virtual. */
    virtual ~ISerCartao() {}
};


#endif // ISERCARTAO_H_INCLUDED
