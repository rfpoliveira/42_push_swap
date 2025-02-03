/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:19:43 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 12:37:03 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sig;
	long	res;

	res = 0;
	i = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	if (str[i] == '+' && str[i - 1] != '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * sig);
}

int	check_arg(char *n)
{
	long	numb;
	int		i;

	i = 0;
	if (n[0] == '-' || n[0] == '+')
		i++;
	while (n[i])
	{
		if (ft_isdigit(n[i]) == 0)
			return (-1);
		i++;
	}
	if (i > 11)
		return (-1);
	numb = ft_atol(n);
	if (numb > INT_MAX || numb < INT_MIN)
		return (-1);
	return (0);
}

static int	parsing_util(char **mtx, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i <= argc - 2)
	{
		j = i + 1;
		while (j <= argc - 2)
		{
			if (atol(mtx[i]) == atol(mtx[j]))
				return (-1);
			j++;
		}
		if (check_arg(mtx[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

char	**parsing(int argc, char **argv)
{
	int	args;
	int	n;

	args = 1;
	n = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		while (argv[n])
			n++;
		args = 0;
		n += 1;
	}
	else
		n = argc;
	if (parsing_util(argv + args, n) == -1)
	{
		if (argc == 2)
			matrix_free(argv);
		return (NULL);
	}
	return (argv + args);
}
