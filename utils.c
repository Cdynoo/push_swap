/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:29:58 by olmohame          #+#    #+#             */
/*   Updated: 2024/02/01 12:30:00 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*dc_get_min(t_list **stack)
{
	t_list	*temp;
	t_list	*minnode;

	minnode = NULL;
	if (stack && *stack)
	{
		(*stack)->prev->next = NULL;
		temp = *stack;
		while (temp)
		{
			if (!minnode || temp->num < minnode->num)
				minnode = temp;
			temp = temp->next;
		}
		(*stack)->prev->next = *stack;
	}
	return (minnode);
}

t_list	*dc_get_max(t_list **stack)
{
	t_list	*temp;
	t_list	*maxnode;

	maxnode = NULL;
	if (stack && *stack)
	{
		(*stack)->prev->next = NULL;
		temp = *stack;
		while (temp)
		{
			if (!maxnode || temp->num > maxnode->num)
				maxnode = temp;
			temp = temp->next;
		}
		(*stack)->prev->next = *stack;
	}
	return (maxnode);
}

int	dc_edge(t_list **stack, t_list *node)
{
	int		maximum;
	int		minimum;
	t_list	*temp;

	if (stack && *stack && node)
	{
		maximum = 1;
		minimum = 1;
		(*stack)->prev->next = NULL;
		temp = *stack;
		while (temp)
		{
			if (temp->num < node->num)
				minimum = 0;
			if (temp->num > node->num)
				maximum = 0;
			temp = temp->next;
		}
		(*stack)->prev->next = *stack;
		if (minimum || maximum)
			return (1);
	}
	return (0);
}

void	dc_rot_or_rev(t_list **stack, int rotations)
{
	int	len;
	int	rev;

	len = dc_count(stack);
	rev = (len - rotations);
	if (rotations <= (len - rotations))
		while (rotations--)
			dc_rotate(stack, "ra\n");
	else
		while (rev--)
			dc_reverse_rot(stack, "rra\n");
}

void	dc_possiblemoves(t_list **stack_a, t_list **stack_b)
{
	int		len;
	t_list	*node;

	node = (*stack_a);
	len = dc_count(stack_a);
	while (len)
	{
		len--;
		dc_req(stack_a, node, stack_b);
		node = node->next;
	}
}
