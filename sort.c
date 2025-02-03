/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:44:41 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/19 12:01:45 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*target;
	long	best;

	while (a)
	{
		best = LONG_MIN;
		while (b)
		{
			if (b->numb < a->numb && b->numb > best)
			{
				best = b->numb;
				target = b;
			}
			if (b->next == NULL)
				break ;
			b = b->next;
		}
		b = go_first_node(b);
		if (best == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	get_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	calc_med(a, b);
	len_a = node_count(a);
	len_b = node_count(b);
	while (a)
	{
		a->cost = a->index;
		if (a->index > a->med)
			a->cost = len_a - (a->index);
		if (a->target->index < b->med)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

static void	endgame(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		index;

	tmp = get_min(*a);
	index = tmp->index;
	calc_med(*a, *b);
	while ((*a)->numb != tmp->numb)
	{
		if (index <= (*a)->med)
			mov_rot(a, b, "ra");
		else
			mov_rev_rot(a, b, "rra");
	}
}

static int	low_number(t_node **a, t_node **b)
{
	if (!(ft_is_sort(*a)))
		return (-1);
	if (node_count(*a) == 2)
	{
		mov_swap(a, b, "sa");
		return (-1);
	}
	if (node_count(*a) <= 3)
	{
		sort3(a, b);
		return (-1);
	}
	return (0);
}

void	algoritm(t_node **a, t_node **b)
{
	if (low_number(a, b) == -1)
		return ;
	mov_push(a, b, "pb");
	if (node_count(*a) > 3 && ft_is_sort(*a))
		mov_push(a, b, "pb");
	while (node_count(*a) > 3 && ft_is_sort(*a))
	{
		init_nodes_a(*a, *b);
		move_to_b(a, b);
	}
	sort3(a, b);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_to_a(a, b);
	}
	atribute_index(*a);
	endgame(a, b);
}
