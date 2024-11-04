/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:46:22 by malves-b          #+#    #+#             */
/*   Updated: 2024/06/02 12:59:55 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

static	void	rotate(t_stack **stack)
{
	t_stack	*aux;

	if (!*stack || !(*stack)->next)
		return ;
	aux = find_last(*stack);
	aux->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	aux->next->prev = aux;
	aux->next->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
