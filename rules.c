/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:02:44 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/18 12:17:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_node **a)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	while ((*a)->next)
		(*a) = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->prev = *a;
	(*a)->next->next = NULL;
	*a = go_first_node(*a);
}

static void	first_push_b(t_node **a, t_node **b)
{
	*b = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	(*b)->prev = NULL;
	(*b)->next = NULL;
}

void	push(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*b)
		return ;
	if (*a == NULL)
	{
		first_push_b(b, a);
		return ;
	}
	tmp = *b;
	if ((*b)->next)
		*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = (*a)->prev;
	if (*b == *a)
		*b = NULL;
}

void	swap(t_node **a)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	tmp->prev = *a;
	(*a)->prev = NULL;
	if ((*a)->next)
		(*a)->next->prev = tmp;
	(*a)->next = tmp;
	*a = go_first_node(*a);
}

void	rev_rotate(t_node **a)
{
	t_node	*tmp;

	if (!*a)
		return ;
	while ((*a)->next)
		*a = (*a)->next;
	tmp = *a;
	*a = (*a)->prev;
	(*a)->next = NULL;
	*a = go_first_node(*a);
	(*a)->prev = tmp;
	tmp->next = *a;
	*a = (*a)->prev;
	(*a)->prev = NULL;
}
