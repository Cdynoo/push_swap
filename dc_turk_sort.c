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

static t_list	*dc_get_mincost(t_streak **longest)
{
	t_list	*temp;
	t_list	*minnode;

	minnode = NULL;
	temp = (*longest)->last->next;
	while (temp != (*longest)->first)
	{
		if (!minnode || sum(temp->op) < sum(minnode->op))
			minnode = temp;
		temp = temp->next;
	}
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
	while (node->op[start] && node->op[start + 2])
	{
		node->op[start]--;
		node->op[start + 2]--;
		node->op[start + 4]++;
	}
	return (node->op[start] + node->op[start + 2] + node->op[start + 4]);
}

static void	opttrim(t_streak **longest)
{
	t_list	*node;

	node = (*longest)->last->next;
	while (node != (*longest)->first)
	{
		zeromoves(node, reduce(node, 0) < reduce(node, 1));
		node = node->next;
	}
}

void	dc_doop(t_list **stack_a, t_list **stack_b, t_list *node)
{
	int	len;

	while (node->op[0]--)
		dc_rotate(stack_a, "ra\n");
	while (node->op[2]--)
		dc_rotate(stack_b, "rb\n");
	while (node->op[4]--)
		dc_rr(stack_a, stack_b);
	while (node->op[1]--)
		dc_reverse_rot(stack_a, "rra\n");
	while (node->op[3]--)
		dc_reverse_rot(stack_b, "rrb\n");
	while (node->op[5]--)
		dc_rrr(stack_a, stack_b);
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

void	testm(t_list **stack_a, t_list **stack_b, int len )
{
	t_list	*nextnode;
	t_streak *longest;
	dc_push(stack_a, stack_b, "pb\n");
	dc_push(stack_a, stack_b, "pb\n");


	while (!dc_issorted(stack_a, len))
	{
		if (!dc_issorted(stack_a, len))
		{
			longest = dc_getsequence(stack_a, len);
			dc_filtersorted(&longest);
			dc_possiblemoves(stack_a, stack_b, &longest);
			opttrim(&longest);
			nextnode = dc_get_mincost(&longest);
			//printf("testmNode {%ld}, rot_a {%d}, revrot_a {%d}, rot_b {%d}, revrot_b {%d}\n", nextnode->num, nextnode->op[0], nextnode->op[1], nextnode->op[2], nextnode->op[3]);
			dc_doop(stack_a, stack_b, nextnode);
			dc_setz(stack_a);
			dc_push(stack_a, stack_b, "pb\n");
		}

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
		//printf("finished indexing\n");
		longest = dc_getsequence(&stack_a, len);
		//printf("Start{%ld}, end{%ld}, len{%d}\n", longest->first->num, longest->last->num, longest->len);
		//dc_filtersorted(&longest);
		//dc_show(&stack_a);
		testm(&stack_a, &stack_b, len);
		/*printf("A: ");
		dc_show(&stack_a);
		printf("B: ");
		dc_show(&stack_b);*/
	}
}
