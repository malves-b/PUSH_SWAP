/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:08:16 by malves-b          #+#    #+#             */
/*   Updated: 2024/05/25 17:16:52 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

static	void	push(t_stack **dst, t_stack **src)
{
	t_stack	*aux;

	if (!*src)
		return ;
	aux = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	aux->prev = NULL;
	if (!*dst)
	{
		*dst = aux;
		aux->next = NULL;
	}
	else
	{
		aux->next = *dst;
		aux->next->prev = aux;
		*dst = aux;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
