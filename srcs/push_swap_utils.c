/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:29:16 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
/* -------------------------------------------------------------------------- */

int	stack_len(t_stack **stack)
{
	int		len;
	t_stack	*aux;

	if (!*stack)
		return (0);
	aux = *stack;
	len = 1;
	while (aux->next)
	{
		aux = aux->next;
		len++;
	}
	return (len);
}
/* -------------------------------------------------------------------------- */

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
/* -------------------------------------------------------------------------- */

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(&stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_mediam = true;
		else
			stack->above_mediam = false;
		stack = stack->next;
		++i;
	}
}
/* -------------------------------------------------------------------------- */

void	before_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_mediam)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_mediam)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
