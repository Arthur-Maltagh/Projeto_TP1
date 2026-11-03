#ifndef DRIVERMAIC_H_INCLUDED
#define DRIVERMAIC_H_INCLUDED

/**
 * @file DriverMAIC.h
 * @brief Declaracao do driver do modulo de apresentacao principal.
 */


/**
 * @brief Executa o MAIC ligado aos modulos de autenticacao e de pessoas.
 *
 * Usa as controladoras reais de autenticacao e de pessoas (apresentacao e
 * servico) e um stub para o modulo de projetos. Permite percorrer o fluxo
 * criar conta, entrar e abrir o menu de pessoas.
 * @return 0 ao terminar.
 */
int executarDriverMAIC();

#endif // DRIVERMAIC_H_INCLUDED
