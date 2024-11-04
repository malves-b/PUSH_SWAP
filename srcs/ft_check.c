/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:15:52 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 12:09:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

int	check_argv(int argc, const char **argv)
{
	int	i;

	i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	while (argc > 1)
	{
		while (argv[argc - 1][i])
		{
			if (!(ft_isdigit(argv[argc - 1][i]) || argv[argc - 1][i] == ' '))
				return (0);
			i++;
		}
		argc--;
		i = 0;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */

int	ft_check(int argc, const char **argv)
{
	if (!check_argv(argc, argv))
		return (0);
	if (argc == 2)
	{
		if (!check_duplicate(argv))
			return (0);
	}
	else if (argc > 2)
	{
		if (!check_duplicate2(argc, argv))
			return (0);
	}
	return (1);
}

/* -------------------------------------------------------------------------- */

int	check_duplicate(const char **argv)
{
	int		i;
	int		j;
	char	**nbrs;

	i = -1;
	nbrs = ft_split(argv[1], ' ');
	if (!nbrs || !*nbrs)
		return (0);
	while (nbrs[++i])
	{
		j = 0;
		while (nbrs[j])
		{
			if ((ft_strncmp(nbrs[i], nbrs[j], \
				ft_strlen(nbrs[i])) == 0 && i != j) \
				|| ft_atol(nbrs[i]) > INT_MAX || ft_atol(nbrs[i]) < INT_MIN)
			{
				ft_free((void **)nbrs, 'p');
				return (0);
			}
			j++;
		}
	}
	ft_free((void **)nbrs, 'p');
	return (1);
}

/* -------------------------------------------------------------------------- */

int	check_duplicate2(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if ((ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				&& i != j)
				return (0);
			else if (ft_atol(argv[j]) > INT_MAX || ft_atol(argv[j]) < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
