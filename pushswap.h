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

# include <stdio.h>

typedef struct s_list
{
	long			num;
	int				i;
	int				*op;
	int				moves;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct streak
{
	int				len;
	struct s_list	*first;
	struct s_list	*last;
}					t_streak;

void		*ft_calloc(size_t nitems, size_t size);
int			is_sorted(long *arr, int len);
void		sort_list(long *arr, int len);
size_t		ft_strlen(const char *str);

t_list		*dc_new_node(long number, int i);
void		dc_add_back(t_list **lst, t_list *newnode);
void		dc_add_front(t_list **lst, t_list *newnode);
t_list		*dc_pop(t_list **lst);
void		dc_clear(t_list **lst);

int			match(long *list_a, int len, long num);
void		dc_indexit(t_list	**lst, long *arr, int len);
int			dc_count(t_list **lst);
void		dc_show(t_list **lst);
//void		dc_showr(t_list **lst);
int			dc_issorted(t_list **lst, int len);
//int			dc_asorted(t_list **lst);
t_list		*dc_build_list(long *list_a, int len);

int			dc_num_rot(t_list *from, t_list *to);
int			dc_count_revrot(t_list *from, t_list *to);
int			dc_swap(t_list **lst, char *str);
int			dc_ss(t_list **stack_a, t_list **stack_b);
int			dc_push(t_list **from, t_list **to, char *str);
int			dc_rotate(t_list **lst, char *str);
int			dc_rr(t_list **stack_a, t_list **stack_b);
int			dc_reverse_rot(t_list **lst, char *str);
int			dc_rrr(t_list **stack_a, t_list **stack_b);
void		dc_rot_or_rev(t_list **stack, int rotations);

t_streak	*dc_longeststreak(t_list **stack);
t_streak	*dc_cyclestreak(t_list **stack);

t_streak	*dc_getstreak(t_list **stack);
int			dc_updatestreak(t_list **stack);

void		dc_naive_sort(t_list	*stack_a, long *arr, int len);

void		dc_movenode(t_list **stack_a, t_list **stack_b, int len);
t_list		*dc_findnext(t_list *needle, t_list **haystack, int len);
void		dc_rot_or_revb(t_list **stack, int rotations);

void		*ft_memset(void *ptr, int c, size_t len);

void		dc_possiblemoves(t_list **stack_a, t_list **stack_b);

void		testm(t_list **stack_a, t_list **stack_b);

void		dc_sort(t_list	*stack_a, long *arr, int len);
#endif