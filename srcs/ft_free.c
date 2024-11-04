/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:41:49 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

void	ft_free(void **ptr, char type)
{
	int			i;
	void		**array;
	t_stack		*node;

	array = (void **)ptr;
	if (!ptr || !*ptr)
		return ;
	if (type == 'p')
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
	else if (type == 's')
	{
		while (*ptr)
		{
			node = *(t_stack **)ptr;
			*ptr = (*(t_stack **)ptr)->next;
			free(node);
		}
	}
}
