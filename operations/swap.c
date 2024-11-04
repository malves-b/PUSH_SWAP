/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:42:39 by malves-b          #+#    #+#             */
/*   Updated: 2024/06/02 13:02:55 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

static	void	swap(t_stack **node)
{
	t_stack	*first;
	t_stack	*second;

	first = *node;
	second = (*node)->next;
	if (!*node || !(*node)->next)
		return ;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*node = second;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf ("sa\n");
}

void	sb(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
