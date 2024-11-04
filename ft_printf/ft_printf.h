/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:22:42 by malves-b          #+#    #+#             */
/*   Updated: 2024/05/22 09:49:11 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
// # include <string.h>

int	ft_printf(const char *str, ...);
/**
 * @brief Funcao que printa um caracter
 * @param str char a ser imprimido
 * @return retorna 1
*/
int	ft_print_char(char str);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putnbr_hex(unsigned int n, const char format);
int	ft_print_ptr(unsigned long n);
int	ft_unsnbr(unsigned int str);

#endif
