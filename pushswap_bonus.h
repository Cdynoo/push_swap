/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 05:09:20 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/31 05:09:23 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

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

void		dc_testsort(t_list	*stack_a, long *arr, int len);
int			validate(int argc, char **argv);
int			ls_is_sorted(long *arr, int len);
t_list		*dc_new_node(long number, int i);
void		dc_add_back(t_list **lst, t_list *newnode);
void		dc_add_front(t_list **lst, t_list *newnode);
t_list		*dc_pop(t_list **lst);
void		dc_clear(t_list **lst);
void		dc_indexit(t_list	**lst, long *arr, int len);
int			dc_count(t_list **lst);
int			dc_issorted(t_list **lst);
t_list		*dc_build_list(long *list_a, int len);
int			dc_swap_t(t_list **lst, char *str, int test);
int			dc_ss_t(t_list **stack_a, t_list **stack_b, int test);
int			dc_push_t(t_list **from, t_list **to, char *str, int test);
int			dc_rotate_t(t_list **lst, char *str, int test);
int			dc_reverse_rot_t(t_list **lst, char *str, int test);
int			dc_rr_t(t_list **stack_a, t_list **stack_b, int test);
int			dc_rrr_t(t_list **stack_a, t_list **stack_b, int test);
#endif
