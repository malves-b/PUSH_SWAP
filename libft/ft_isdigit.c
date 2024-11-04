/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:51:55 by malves-b          #+#    #+#             */
/*   Updated: 2024/06/09 18:46:05 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9') || (i == '-' || i == '+'))
		return (2048);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    printf("%i\n", isdigit('8'));
    printf("%i", ft_isdigit('5'));
}*/
