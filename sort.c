/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:11:56 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/03 05:11:58 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*dc_findstart(t_list **stack)
{
	int		size;
	t_list	*temp;

	temp = *stack;
	size = dc_count(stack);
	while (size-- >= 0)
	{
		if (!(temp->i))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

static void	dc_arrange(t_list	**stack)
{
	t_list	*head;

	head = dc_findstart(stack);
	dc_rot_or_revb(stack, dc_num_rot(head, *stack));
}

static void	dc_keeplongestsequence(t_list *stack_a, t_list *stack_b, int len)
{
	dc_updatestreak(&stack_a);
	while (!dc_issorted(&stack_a, len))
	{
		if (((stack_a)->i) == ((stack_a)->next->i + 1))
		{
			dc_swap(&stack_a, "sa\n");
			continue ;
		}
		if (((stack_a)->i) == ((stack_a)->prev->i + 1) % len)
		{
			dc_rotate(&stack_a, "ra\n");
			continue ;
		}
		if (!dc_issorted(&stack_a, len))
			dc_push(&stack_a, &stack_b, "pb\n");
	}
}

void	dc_naive_sort(t_list *stack_a, long *arr, int len)
{
	t_list		*stack_b;

	stack_b = NULL;
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		dc_keeplongestsequence(stack_a, stack_b, len);
		while (dc_count(&stack_b))
			dc_movenode(&stack_a, &stack_b, len);
		dc_updatestreak(&stack_a);
		dc_arrange(&stack_a);
		dc_clear(&stack_a);
	}
}
