/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:13:45 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 10:16:17 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

/*============================================================================#
#                                 Libraries                                   #
#============================================================================*/

# include "libft/libft.h"

/*============================================================================#
#                                 Structs                                     #
#============================================================================*/

typedef struct s_node
{
	int				numb;
	int				index;
	int				cheap;
	int				cost;
	int				med;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*============================================================================#
#                                 Functions                                   #
#============================================================================*/

/*	parsing */
int		check_arg(char *n);
char	**parsing(int argc, char **argv);

/*	utils */
long	ft_atol(char *str);
int		node_count(t_node *a);
void	sort3(t_node **a, t_node **b);
int		ft_is_sort(t_node *a);
void	is_cheap(t_node *a);
t_node	*get_max(t_node *b);
t_node	*get_min(t_node *b);
void	calc_med(t_node *a, t_node *b);

/* handling lists */
t_node	*ft_list_ini(char **argv);
t_node	*go_first_node(t_node *lst);
void	node_add_back(t_node *lst, t_node *curr);
t_node	*new_node(int content);
void	init_nodes_a(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);

/* sorting functions */
void	swap(t_node **a);
void	push(t_node **a, t_node **b);
void	rotate(t_node **a);
void	rev_rotate(t_node **a);

/*select movement*/
void	mov_swap(t_node **a, t_node **b, char *c);
void	mov_push(t_node **a, t_node **b, char *c);
void	mov_rot(t_node **a, t_node **b, char *c);
void	mov_rev_rot(t_node **a, t_node **b, char *c);
void	rot_both(t_node **a, t_node **b, t_node *cheap, int i);

/* algoritm and memory */
void	algoritm(t_node **a, t_node **b);
void	set_target_a(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);
void	get_cost(t_node *a, t_node *b);
void	atribute_index(t_node *a);
void	get_on_top(t_node **a, t_node **b, t_node *cheap, char name);
void	move_to_b(t_node **a, t_node **b);
void	move_to_a(t_node **a, t_node **b);
void	free_lst(t_node *a);

#endif
