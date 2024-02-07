/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 04:09:25 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/01 04:09:31 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_list
{
	long			num;
	int				i;
	int				*op;
	int				moves;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int			ls_is_sorted(long *arr, int len);
void		dc_indexit(t_list	**lst, long *arr, int len);
void		opttrim(t_list **stack);
t_list		*dc_get_mincost(t_list **stack);
t_list		*dc_new_node(long number, int i);
void		dc_add_back(t_list **lst, t_list *newnode);
void		dc_add_front(t_list **lst, t_list *newnode);
t_list		*dc_pop(t_list **lst);
void		dc_clear(t_list **lst);
t_list		*dc_build_list(long *list_a, int len);
int			dc_count(t_list **lst);
int			dc_issorted(t_list **lst);
int			dc_issubsorted(t_list **lst);
int			dc_swap(t_list **lst, char *str);
int			dc_ss(t_list **stack_a, t_list **stack_b);
int			dc_push(t_list **from, t_list **to, char *str);
int			dc_num_rot(t_list *from, t_list *to);
int			dc_num_revrot(t_list *from, t_list *to);
int			dc_rotate(t_list **lst, char *str);
int			dc_rr(t_list **stack_a, t_list **stack_b);
int			dc_reverse_rot(t_list **lst, char *str);
int			dc_rrr(t_list **stack_a, t_list **stack_b);
void		dc_arrange(t_list	**stack, t_list	*head);
void		dc_possiblemoves(t_list **stack_a, t_list **stack_b);
void		dc_possiblemovesto_a(t_list **stack_a, t_list **stack_b);
void		dc_req(t_list **stack_a, t_list *node, t_list **stack_b);
void		dc_sort(t_list	*stack_a, long *arr, int len);
int			validate(int argc, char **argv);
t_list		*dc_get_min(t_list **stack);
t_list		*dc_get_max(t_list **stack);
int			dc_edge(t_list **stack, t_list *node);
void		dc_rot_or_rev(t_list **stack, int rotations);
#endif