/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:54:35 by malves-b          #+#    #+#             */
/*   Updated: 2023/10/17 16:52:46 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Funcao que aloca espaco de memoria para um bloco de dados
Na funcao calloc os lixos de memoria sao deletados, ou seja,
inicializa com '0' */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*x;

	x = malloc(n * size);
	if (x == NULL)
		return (x);
	ft_bzero(x, n * size);
	return (x);
}
/* 
int main(void)
{
    int *a1;
    int i;

    a1 = (int *) ft_calloc(sizeof(int), 4);
    i = 0;
    while (i < sizeof(a1))
    {
        printf("%i\n", *a1);
        i++;
    }
    printf("%lu", sizeof(int));
    return 0;
} */
