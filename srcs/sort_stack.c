/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:56:33 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:23 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	pb(a, b, false);
	if (stack_len(a) > 3)
		pb (a, b, false);
	while (stack_len(a) > 3)
	{
		init_nodes_a(*a, *b);
		move_to_b(a, b);
	}
	if ((stack_len(a) + stack_len(b)) > 3)
		sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_to_a(a, b);
	}
	if ((stack_len(a) + stack_len(b)) > 3)
		current_index(*a);
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_mediam)
			ra(a, false);
		else
			rra(a, false);
	}
}
/* -------------------------------------------------------------------------- */

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_mediam && cheapest->target_node->above_mediam)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_mediam))
		rev_rotate_both(a, b, cheapest);
	before_push(a, cheapest, 'a');
	before_push(b, cheapest->target_node, 'b');
	pb(a, b, false);
}
/* -------------------------------------------------------------------------- */

void	move_to_a(t_stack **a, t_stack **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

/* -------------------------------------------------------------------------- */

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_a_to_b(a, b);
	set_cheapest(a);
}
/* -------------------------------------------------------------------------- */

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
