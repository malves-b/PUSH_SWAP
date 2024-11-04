/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:52:31 by malves-b          #+#    #+#             */
/*   Updated: 2024/06/02 12:55:54 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*aux;

	if (!*stack || !(*stack)->next)
		return ;
	aux = find_last(*stack);
	aux->prev->next = NULL;
	aux->next = *stack;
	aux->prev = NULL;
	*stack = aux;
	aux->next->prev = aux;
}

void	rra(t_stack **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
