/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:47:59 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

t_stack	*find_max(t_stack *a)
{
	t_stack	*max_node;

	max_node = a;
	if (!a)
		return (NULL);
	while (a != NULL)
	{
		if (a->nbr > max_node->nbr)
			max_node = a;
		a = a->next;
	}
	return (max_node);
}
/* -------------------------------------------------------------------------- */

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;

	min_node = stack;
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->nbr < min_node->nbr)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}
/* -------------------------------------------------------------------------- */

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
/* -------------------------------------------------------------------------- */

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
/* -------------------------------------------------------------------------- */

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
