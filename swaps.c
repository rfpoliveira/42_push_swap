/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:47 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/18 17:32:23 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	mov_swap(t_node **a, t_node **b, char *c)
{
	if (c[1] == 'a' || c[1] == 's')
	{
		swap(a);
		atribute_index(*a);
	}
	if (c[1] == 'b' || c[1] == 's')
	{
		swap(b);
		atribute_index(*b);
	}
	ft_printf("%s\n", c);
}

void	mov_push(t_node **a, t_node **b, char *c)
{
	if (c[1] == 'a')
		push(a, b);
	else if (c[1] == 'b')
		push(b, a);
	atribute_index(*a);
	atribute_index(*b);
	ft_printf("%s\n", c);
}

void	mov_rot(t_node **a, t_node **b, char *c)
{
	if (c[1] == 'a' || c[1] == 'r')
	{
		rotate(a);
		atribute_index(*a);
	}
	if (c[1] == 'b' || c[1] == 'r')
	{
		rotate(b);
		atribute_index(*b);
	}
	ft_printf("%s\n", c);
}

void	mov_rev_rot(t_node **a, t_node **b, char *c)
{
	if (c[2] == 'a' || c[2] == 'r')
	{
		rev_rotate(a);
		atribute_index(*a);
	}
	if (c[2] == 'b' || c[2] == 'r')
	{
		rev_rotate(b);
		atribute_index(*b);
	}
	ft_printf("%s\n", c);
}

void	rot_both(t_node **a, t_node **b, t_node *cheap, int i)
{
	if (i == 1)
	{
		while (*a != cheap && *b != cheap->target)
			mov_rot(a, b, "rr");
	}
	else
	{
		while (*a != cheap && *b != cheap->target)
			mov_rev_rot(a, b, "rrr");
	}
}
