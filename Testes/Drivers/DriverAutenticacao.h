#ifndef DRIVERAUTENTICACAO_H_INCLUDED
#define DRIVERAUTENTICACAO_H_INCLUDED

/**
 * @file DriverAutenticacao.h
 * @brief Declaracao dos drivers do modulo de autenticacao.
 */

/**
 * @brief Driver interativo da apresentacao de autenticacao (MAAU).
 *
 * Usa um stub do servico que aceita ana@teste.com com a senha abc12.
 * @return 0 ao terminar.
 */
int executarDriverAutenticacao();

/**
 * @brief Teste automatico do servico de autenticacao (MSAU).
 *
 * Usa um stub do servico de pessoas e verifica um cenario de sucesso e
 * dois de falha.
 * @return 0 se todos os casos foram aprovados; diferente de 0 caso contrario.
 */
int executarTesteServicoAutenticacao();

#endif // DRIVERAUTENTICACAO_H_INCLUDED
