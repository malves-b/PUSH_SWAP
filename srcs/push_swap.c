/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:39:28 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

t_stack	*ft_add_node(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return (NULL);
	new_node = ft_calloc(sizeof(t_stack), 1);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (new_node);
}
/* -------------------------------------------------------------------------- */

t_stack	*start_stack(int argc, char **argv)
{
	t_stack	*top;
	char	**nbrs;
	int		i;

	top = NULL;
	if (argc == 2)
	{
		nbrs = ft_split(argv[1], ' ');
		i = 0;
		while (nbrs[i])
		{
			ft_add_node(&top, ft_atoi(nbrs[i]));
			i++;
		}
		ft_free((void **)nbrs, 'p');
	}
	if (argc > 2)
	{
		while (argc-- > 1)
		{
			ft_add_node(&top, ft_atoi(*++argv));
		}
	}
	return (top);
}
/* -------------------------------------------------------------------------- */

void	ft_sort(t_stack **a, t_stack **b)
{
	if (stack_len(a) == 2)
		sa(a, false);
	else if (stack_len(a) == 3)
		sort_three(a);
	else if (stack_len(a) > 3)
	{
		sort_stack(a, b);
	}
}

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (!ft_check(argc, argv))
		{
			ft_printf("Error\n");
			return (0);
		}
		a = start_stack(argc, (char **)argv);
		if (!a)
		{
			ft_free((void **)a, 's');
			return (0);
		}
		if (!is_sorted(a))
			ft_sort(&a, &b);
		ft_free((void **)b, 's');
	}
	if (a)
		ft_free((void *)&a, 's');
	return (0);
}

/*void	ft_print_stack(t_stack *a)
{
	t_stack	*aux;

	aux = a;
	while (aux != NULL)
	{
		ft_printf("\n --- %d --- \n", aux->nbr);
		aux = aux->next;
	}
}
set variable argc = 2
set variable argv[1] = "10 30 20 50 2"*/
