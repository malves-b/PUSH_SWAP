/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:59:37 by malves-b          #+#    #+#             */
/*   Updated: 2023/11/09 13:54:58 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlen_hex(unsigned long long n)
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

static int	ft_putnbr_long(unsigned long long n)
{
	int	i;

	i = strlen_hex(n);
	if (n >= 16)
	{
		ft_putnbr_long(n / 16);
		ft_putnbr_long(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_print_char((n + '0'));
		else
			ft_print_char(n - 10 + 'a');
	}
	return (i);
}

int	ft_print_ptr(unsigned long n)
{
	int		ret;

	ret = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ret += ft_putstr("0x");
	ret += ft_putnbr_long(n);
	return (ret);
}
/*
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 20; 
    
    int *a1;
    int *a2;
    
    a1 = &x;
    a2 = &y;


    // ft_printf("%p", a1);
    printf("%p", a1);
    
    return 0;
}*/
