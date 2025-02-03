/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:56:00 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/27 15:27:07 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_node	*get_cheapest(t_node *a)
{
	while (a->cheap != 1)
		a = a->next;
	return (a);
}

void	get_on_top(t_node **a, t_node **b, t_node *cheap, char name)
{
	while (*a != cheap)
	{
		if (name == 'a')
		{
			if (cheap->index <= (*a)->med)
				mov_rot(a, b, "ra");
			else
				mov_rev_rot(a, b, "rra");
		}
		else if (name == 'b')
		{
			if (cheap->index <= (*a)->med)
				mov_rot(b, a, "rb");
			else
				mov_rev_rot(b, a, "rrb");
		}
	}
}

void	move_to_b(t_node **a, t_node **b)
{
	t_node	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->index > (*a)->med && cheap->target->index > (*b)->med)
		rot_both(a, b, cheap, 0);
	if (cheap->index < (*a)->med && cheap->target->index < (*b)->med && \
	cheap->target != *b && cheap != *a)
		rot_both(a, b, cheap, 1);
	get_on_top(a, b, cheap, 'a');
	get_on_top(b, a, cheap->target, 'b');
	mov_push(a, b, "pb");
}

void	move_to_a(t_node **a, t_node **b)
{
	get_on_top(a, b, (*b)->target, 'a');
	mov_push(a, b, "pa");
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*target;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		while (a)
		{
			if (a->numb > b->numb && a->numb < best)
			{
				best = a->numb;
				target = a;
			}
			if (a->next == NULL)
				break ;
			a = a->next;
		}
		a = go_first_node(a);
		if (best == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
