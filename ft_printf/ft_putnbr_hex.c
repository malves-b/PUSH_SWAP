/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:46:36 by malves-b          #+#    #+#             */
/*   Updated: 2023/11/09 12:58:41 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlen_hex(long n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		ret++;
	}
	return (ret);
}

int	ft_putnbr_hex(unsigned int n, const char format)
{
	int	i;

	i = strlen_hex(n);
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, format);
		ft_putnbr_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_print_char((n + '0'));
		else
		{
			if (format == 'x')
				ft_print_char(n - 10 + 'a');
			if (format == 'X')
				ft_print_char(n - 10 + 'A');
		}
	}
	return (i);
}
/* 
#include <stdio.h>

int main(int argc, char const *argv[])
{
    ft_putnbr_hex atoi(argv[1], 'X');
    printf("\n%X", atoi(argv[1]));
    return 0;
} */
