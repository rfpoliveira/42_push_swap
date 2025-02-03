/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:23:44 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/18 11:41:32 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	node_count(t_node *a)
{
	int	i;

	i = 1;
	if (a->next == NULL)
		return (1);
	while (a->next)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	atribute_index(t_node *a)
{
	int	i;

	i = 1;
	while (a)
	{
		a->index = i;
		i++;
		a = a->next;
	}
}

t_node	*go_first_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	node_add_back(t_node *lst, t_node *curr)
{
	if (!curr)
		return ;
	if (!lst)
	{
		lst = curr;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = curr;
	lst->next->prev = lst;
	lst = go_first_node(lst);
}

t_node	*new_node(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->index = 0;
	new->cheap = 0;
	new->med = 0;
	new->numb = content;
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	return (new);
}
