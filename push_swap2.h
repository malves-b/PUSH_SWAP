/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:00:14 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:08:55 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP2_H
# define PUSH_SWAP2_H

# include "push_swap.h"

/* -------------------------------------------------------------------------- */
/*                                    SORT                                    */
/* -------------------------------------------------------------------------- */

t_stack	*start_stack(int argc, char **argv);
void	ft_sort(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);

void	move_to_a(t_stack **a, t_stack **b);
void	move_to_b(t_stack **a, t_stack **b);
void	init_nodes_a(t_stack *a, t_stack *b);

/**
 * @brief Funcao que define o No mais em conta para o push
*/
void	set_cheapest(t_stack *stack);
/**
 * @brief Funcao que pega o No mais em conta para o push
*/
t_stack	*get_cheapest(t_stack *stack);
/**
 * @brief Funcao que organiza uma stack com 3 elementos
*/
void	sort_three(t_stack **a);
/**
 * @brief Funcao que coloca o No mais barato da pilha no topo
*/
void	before_push(t_stack **stack, t_stack *top_node, char stack_name);
/**
 * @brief Funcao que encontra o destido do No A na stack B
*/
void	set_target_a(t_stack *a, t_stack *b);
/**
 * @brief Funcao que analisa custo do push do no A para o B
*/
void	init_b(t_stack *a, t_stack *b);
/**
 * @brief Funcao que calcula o custo de operacoes para o No chegar em cima
*/
void	cost_a_to_b(t_stack *a, t_stack *b);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/**
 * @brief Funcao que encontra o maior no da stack
*/
t_stack	*find_max(t_stack *a);
/**
 * @brief Funcao que define o index de cada No
*/
void	current_index(t_stack *stack);
/**
 * @brief Funcao que encontra o menor no da stack
*/
t_stack	*find_min(t_stack *stack);
/**
 * @brief Da free em uma stack ou em um Array de ponteiros
 * @param ptr: pointer de um pointer, pode ser uma pilha ou um array de pointer
 * @param type: tipo da operacao, para free em array de pointer, use: 'p' -
 * para free em uma stack, use: 's'
*/
void	ft_free(void **ptr, char type);
/**
 * Funcao que adiciona um no a Stack
*/
t_stack	*ft_add_node(t_stack **stack, int nbr);
/**
 * @brief Funcao que retorna o ponteiro para o ultimo no da Stack
*/
t_stack	*find_last(t_stack *stack);
/**
 * @brief Funcao que verifica o tamanho da Stack
*/
int		stack_len(t_stack **stack);

/* -------------------------------------------------------------------------- */
/*                                    CHECK                                   */
/* -------------------------------------------------------------------------- */
/**
 * @brief Verifica se a t_stack esta ordenada
*/
int		is_sorted(t_stack *check);
/**
 * @brief Verifica se os argumentos da linha de comando sao apenas numeros
 * @returns 1 se houver apenas numeros @return 0 se houver outros caracteres
*/
int		check_argv(int argc, const char **argv);
/**
 * @brief Verifica se tem numeros duplicados
*/
int		check_duplicate(const char **argv);
int		ft_check(int argc, const char **argv);
int		check_duplicate2(int argc, const char **argv);

/* -------------------------------------------------------------------------- */
/*                                 OPERATIONS                                 */
/* -------------------------------------------------------------------------- */

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
/**
 * @brief (Push a): Pega o primeiro elemento do topo de B e coloca no topo de A
*/
void	pa(t_stack **a, t_stack **b, bool print);
/**
 * @brief (Push b): Pega o primeiro elemento do topo de A e coloca no topo de B
*/
void	pb(t_stack **a, t_stack **b, bool print);
/**
 * @brief (Swap a): Troca os dois primeiros elementos do topo da t_stack A.
*/
void	sa(t_stack **a, bool print);
/**
 * @brief (Swap b): Troca os dois primeiros elementos do topo da t_stack B.
*/
void	sb(t_stack **a, bool print);
/**
 * @brief sa e sb ao mesmo tempo
*/
void	ss(t_stack **a, t_stack **b, bool print);
/**
 * @brief (Rotate a): Sobe todos os elementos da t_stack A em 1
*/
void	ra(t_stack **a, bool print);
/**
 * @brief (Rotate b): Sobe todos os elementos da t_stack B em 1
*/
void	rb(t_stack **b, bool print);
/**
 *  ra e rb ao mesmo tempo
*/
void	rr(t_stack **a, t_stack **b, bool print);
/**
 * @brief (reverse rotate a): Desce todos os elementos da t_stack A em 1
*/
void	rra(t_stack **a, bool print);
/**
 * @brief (reverse rotate b): Desce todos os elementos da t_stack B em 1
*/
void	rrb(t_stack **b, bool print);
/**
 * @brief rra e rrb ao mesmo tempo
*/
void	rrr(t_stack **a, t_stack **b, bool print);

#endif
