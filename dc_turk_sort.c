/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:17:03 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/20 03:17:06 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_sort(t_list **stack_a)
{
	if (dc_get_min(stack_a) == (*stack_a))
	{
		dc_reverse_rot(stack_a, "rra\n");
		dc_swap(stack_a, "sa\n");
	}
	else if (dc_get_max(stack_a) == (*stack_a))
	{
		dc_rotate(stack_a, "ra\n");

		if (!dc_asorted(stack_a))
			dc_swap(stack_a, "sa\n");
	}
	else
	{
		if (dc_get_max(stack_a) == (*stack_a)->next)
			dc_reverse_rot(stack_a, "rra\n");
		else
			dc_swap(stack_a, "sa\n");
	}
}

static int	sum(int *op)
{
	int	i;
	int	count;

	i = 6;
	count = 0;
	while (i)
		count += op[--i];
	return (count);
}

static t_list	*dc_get_mincost(t_list **stack)
{
	int		len;
	t_list	*temp;
	t_list	*minnode;

	minnode = NULL;
	temp = *stack;
	len = dc_count(stack);
	while (len)
	{
		//printf("oopNode {%ld}, rot_a {%d}, revrot_a {%d}, rot_b {%d}, revrot_b {%d}, rr {%d}, rrr {%d}\n", temp->num, temp->op[0], temp->op[1], temp->op[2], temp->op[3], temp->op[4], temp->op[5]);
		len--;
		if (!minnode || sum(temp->op) < sum(minnode->op))
			minnode = temp;
		temp = temp->next;
	}
	//temp = minnode;
	//printf("minNode {%ld}, rot_a {%d}, revrot_a {%d}, rot_b {%d}, revrot_b {%d}, rr {%d}, rrr {%d}\n", temp->num, temp->op[0], temp->op[1], temp->op[2], temp->op[3], temp->op[4], temp->op[5]);
	return (minnode);
}

static void	zeromoves(t_list *node, int start)
{
	node->op[start] = 0;
	node->op[start + 2] = 0;
	node->op[start + 4] = 0;
}

static int	reduce(t_list	*node, int start)
{
	while (node->op[start] > 0 && node->op[start + 2] > 0)
	{
		node->op[start]--;
		node->op[start + 2]--;
		node->op[start + 4]++;
	}
	return (node->op[start] + node->op[start + 2] + node->op[start + 4]);
}

static void	opttrim(t_list **stack)
{
	int		len;
	t_list	*node;

	node = (*stack);
	len = dc_count(stack);
	while (len)
	{
		len--;
		zeromoves(node, reduce(node, 0) < reduce(node, 1));
		node = node->next;
	}
}

void	dc_doop(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if (node)
	{
		while (node->op[0] && node->op[0]--)
			dc_rotate(stack_a, "ra\n");
		while (node->op[2] && node->op[2]--)
			dc_rotate(stack_b, "rb\n");
		while (node->op[4] && node->op[4]--)
			dc_rr(stack_a, stack_b);
		while (node->op[1] && node->op[1]--)
			dc_reverse_rot(stack_a, "rra\n");
		while (node->op[3] && node->op[3]--)
			dc_reverse_rot(stack_b, "rrb\n");
		while (node->op[5] && node->op[5]--)
			dc_rrr(stack_a, stack_b);
	}
}

int	dc_setz(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (lst && *lst)
	{
		temp = *lst;
		while (temp->next != *lst)
		{
			ft_memset(temp->op, 0, 6 * sizeof(int));
			temp = temp->next;
		}
	}
	return (1);
}

void	movefromAtoB(t_list **stack_a, t_list **stack_b)
{
	t_list		*nextnode;

	dc_push(stack_a, stack_b, "pb\n");
	while (dc_count(stack_a) > 1)
	{
		dc_possiblemoves(stack_a, stack_b);
		opttrim(stack_a);
		nextnode = dc_get_mincost(stack_a);
		dc_doop(stack_a, stack_b, nextnode);
		dc_setz(stack_a);
		dc_setz(stack_b);
		dc_push(stack_a, stack_b, "pb\n");
	}
	//dc_setz(stack_a);
	//dc_setz(stack_b);
}

void	movefromBtoA(t_list **stack_a, t_list **stack_b)
{
	t_list		*nextnode;

	while (dc_count(stack_a))
	{
		dc_possiblemoves_toA(stack_a, stack_b);
		opttrim(stack_a);
		nextnode = dc_get_mincost(stack_a);
		dc_doop(stack_b, stack_a, nextnode);
		dc_setz(stack_a);
		dc_setz(stack_b);
		dc_push(stack_a, stack_b, "pa\n");
	}
	dc_setz(stack_b);
}

void	dc_sort(t_list	*stack_a, long *arr, int len)
{
	t_list		*stack_b;
	t_streak	*longest;

	stack_b = NULL;
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		movefromAtoB(&stack_a, &stack_b);
		//init_sort(&stack_a);
		movefromBtoA(&stack_b, &stack_a);
		dc_arrange(&stack_a);
		/*if	(dc_asorted(&stack_a))
			printf("OK\n");
		else
			printf("KO\n");
		printf("A: ");
		dc_show(&stack_a);
		printf("B: ");
		dc_show(&stack_b);*/
		dc_clear(&stack_a);
	}
}
