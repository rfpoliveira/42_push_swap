/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:12:51 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/20 12:16:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort3(t_node **a, t_node **b)
{
	t_node	*max;

	max = get_max(*a);
	if (max == *a)
		mov_rot(a, b, "ra");
	if ((*a)->next == max)
		mov_rev_rot(a, b, "rra");
	if ((*a)->numb > (*a)->next->numb)
		mov_swap(a, b, "sa");
}

int	ft_is_sort(t_node *a)
{
	if (!(a->next))
		return (0);
	while (a->next)
	{
		if (a->next->numb < a->numb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	is_cheap(t_node *a)
{
	int	tmp;

	tmp = a->cost;
	while (a->next)
	{
		a = a->next;
		if (a->cost < tmp)
			tmp = a->cost;
	}
	while (a->cost != tmp)
		a = a->prev;
	a->cheap = 1;
}

t_node	*get_max(t_node *b)
{
	int	tmp;

	tmp = b->numb;
	while (b->next)
	{
		b = b->next;
		if (b->numb > tmp)
			tmp = b->numb;
	}
	if (b->numb > tmp)
		tmp = b->numb;
	while (b->numb != tmp)
		b = b->prev;
	return (b);
}

t_node	*get_min(t_node *b)
{
	int	tmp;

	tmp = b->numb;
	while (b->next)
	{
		b = b->next;
		if (b->numb < tmp)
			tmp = b->numb;
	}
	if (b->numb < tmp)
		tmp = b->numb;
	while (b->numb != tmp)
		b = b->prev;
	return (b);
}
