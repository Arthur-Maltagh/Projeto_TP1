/**
 * @mainpage TP1 - Sistema de gestão das classes Kanban
 *
 *
 * As classes estão organizadas nos seguintes grupos:
 * - @ref Dominios : classes que representam e validam o formato dos valores;
 * - @ref Entidades : classes que representam as entidades do sistema.
 *
 * @section autores Autores
 * - Arthur Rodrigues Malta
 * - Maria Eduarda Santana Rodrigues
 * - Murilo Martins Muniz Freire
 * - João victor Marques Leal
 */

/**
 * @defgroup Dominios Classes de domínio
 * @brief Classes que representam os domínios do sistema.
 *
 * Cada classe de domínio encapsula um valor e valida o seu formato.
 * O método set lança invalid_argument quando o formato é inválido.
 */

/**
 * @defgroup Entidades Classes de entidade
 * @brief Classes que representam as entidades do sistema.
 *
 * Cada atributo de uma entidade é uma instância de uma classe de domínio
 * e é acessado pelos métodos públicos set e get.
 */
