/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:37:05 by malves-b          #+#    #+#             */
/*   Updated: 2023/11/09 11:37:07 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnbr(unsigned int str)
{
	unsigned int	i;

	i = 0;
	if (str >= 10)
	{
		i += ft_unsnbr(str / 10);
		i += ft_unsnbr(str % 10);
	}
	if (str < 10)
	{
		ft_print_char(str + '0');
		i++;
	}
	return (i);
}

/* 
#include <stdio.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    int x;
    
    printf("%u\n\n", -500);
    
    i += ft_unsnbr(-500);
    x += printf("\n\n%u\n\n", -500);
    
    printf("\n\n%i\n%i", i, x);
    
    return (0);
}
 */