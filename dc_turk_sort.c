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

static void	init_sort(t_list **stack_a)
{
	while (!dc_issubsorted(stack_a))
	{
		dc_reverse_rot(stack_a, "rra\n");
		if (((*stack_a)->i) > ((*stack_a)->next->i))
			dc_swap(stack_a, "sa\n");
	}
}

static void	dc_doop(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if (node && node->op)
	{
		while (node->op[0] > 0 && node->op[0]--)
			dc_rotate(stack_a, "ra\n");
		while (node->op[2] > 0 && node->op[2]--)
			dc_rotate(stack_b, "rb\n");
		while (node->op[4] > 0 && node->op[4]--)
			dc_rr(stack_a, stack_b);
		while (node->op[1] > 0 && node->op[1]--)
			dc_reverse_rot(stack_a, "rra\n");
		while (node->op[3] > 0 && node->op[3]--)
			dc_reverse_rot(stack_b, "rrb\n");
		while (node->op[5] > 0 && node->op[5]--)
			dc_rrr(stack_a, stack_b);
	}
}

static void	movefrom_a(t_list **stack_a, t_list **stack_b)
{
	t_list		*nextnode;

	dc_push(stack_a, stack_b, "pb\n");
	while (!dc_issorted(stack_a) && (dc_count(stack_a) > 3))
	{
		dc_possiblemoves(stack_a, stack_b);
		opttrim(stack_a);
		nextnode = dc_get_mincost(stack_a);
		dc_doop(stack_a, stack_b, nextnode);
		if (nextnode)
			dc_push(stack_a, stack_b, "pb\n");
	}
}

static void	movefrom_b(t_list **stack_a, t_list **stack_b)
{
	t_list		*nextnode;

	while (dc_count(stack_a))
	{
		dc_possiblemovesto_a(stack_a, stack_b);
		opttrim(stack_a);
		nextnode = dc_get_mincost(stack_a);
		dc_doop(stack_b, stack_a, nextnode);
		if (nextnode)
			dc_push(stack_a, stack_b, "pa\n");
	}
}

void	dc_sort(t_list	*stack_a, long *arr, int len)
{
	t_list		*stack_b;

	stack_b = NULL;
	stack_a = dc_build_list(arr, len);
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		if (dc_count(&stack_a) > 3)
			movefrom_a(&stack_a, &stack_b);
		init_sort(&stack_a);
		movefrom_b(&stack_b, &stack_a);
		dc_arrange(&stack_a, dc_get_min(&stack_a));
		dc_clear(&stack_a);
		dc_clear(&stack_b);
	}
}
