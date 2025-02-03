/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:40:34 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/20 16:42:46 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_lst(t_node *a)
{
	while (a->next)
		a = a->next;
	while (a->prev)
	{
		a = a->prev;
		free(a->next);
	}
	free(a);
}
