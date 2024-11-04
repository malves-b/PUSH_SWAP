/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:35:38 by malves-b          #+#    #+#             */
/*   Updated: 2024/06/02 16:40:52 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/* -------------------------------------------------------------------------- */

static int	check_type(va_list arg, const char *str)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += ft_print_char(va_arg(arg, int));
	else if (*str == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (*str == 'u')
		i += ft_unsnbr(va_arg(arg, int));
	else if (*str == 'x' || *str == 'X')
		i += ft_putnbr_hex(va_arg(arg, int), *str);
	else if (*str == 'p')
		i += ft_print_ptr(va_arg(arg, unsigned long));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX", str[i]))
				ret += check_type(args, &str[i]);
			else if (str[i] == '%')
				ret += ft_print_char('%');
		}
		else
			ret += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
/* -------------------------------------------------------------------------- */

/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i;

	// ft_printf("%s", "teste");
	i = ft_printf("%u\n\n", (argv[1]));
	// i = printf("%s", (argv[1]));
	//printf("%i", i);
	return (0);
}

*/