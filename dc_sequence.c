/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:47:45 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/22 02:47:46 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	dc_dragsequence(t_list **stack, t_streak	*longest)
{
	//dc_show(stack);
	while (longest->last->num != ((*stack)->prev->num))
	{
		dc_rot_or_rev(stack, dc_num_rot(longest->last, (*stack)->prev));
		//dc_show(stack);
	}
}

t_streak	*dc_longestseq(t_list **stack, int len)
{
	t_list		*temp;
	t_streak	*longest;
	t_streak	*currlongest;

	longest = NULL;
	if (stack && *stack)
	{
		longest = dc_new_streak(*stack);
		currlongest = dc_new_streak(*stack);
		temp = *stack;
		while (longest && currlongest && temp->next != *stack)
		{
			if ((temp->i + 1) % len == temp->next->i)
				dc_reset(longest, currlongest, temp, 0);
			else
				dc_reset(longest, currlongest, temp, 1);
			temp = temp->next;
		}
		if (longest->len == 1)
		{
			longest->last = (*stack)->prev;
			longest->first = (*stack)->prev;
		}
		free(currlongest);
		currlongest = NULL;
	}
	return (longest);
}

static t_streak	*dc_lastsequence(t_list **stack, int len)
{
	t_list		*temp;
	t_list		*last;
	t_streak	*longest;

	longest = NULL;
	if (stack && *stack)
	{
		longest = dc_new_streak((*stack)->prev);
		temp = (*stack)->prev;
		last = (*stack)->prev;
		(*stack)->prev = NULL;
		while (temp->prev)
		{
			if (temp->i == (temp->prev->i + 1) % len)
			{
				longest->first = temp->prev;
				longest->len = longest->len + 1;
			}
			else
				break ;
			temp = temp->prev;
		}
		(*stack)->prev = last;
	}
	return (longest);
}

t_streak	*dc_cyclesequence(t_list **stack, int len)
{
	t_list		*temp;
	t_streak	*b_longest;

	b_longest = NULL;
	if (stack && *stack)
	{
		b_longest = dc_lastsequence(stack, len);
		temp = b_longest->last;
		while (1 && temp->next != b_longest->first)
		{
			if ((temp->i + 1) % len == temp->next->i)
			{
				b_longest->last = temp->next;
				b_longest->len = b_longest->len + 1;
			}
			else
				break ;
			temp = temp->next;
		}
	}
	return (b_longest);
}

t_streak	*dc_getsequence(t_list **stack, int len)
{
	t_streak	*longest;
	t_streak	*cyclic_streak;

	longest = dc_longestseq(stack, len);
	cyclic_streak = dc_cyclesequence(stack, len);
	if (cyclic_streak->len >= longest->len)
	{
		free(longest);
		longest = NULL;
		longest = cyclic_streak;
	}
	else
	{
		free(cyclic_streak);
		cyclic_streak = NULL;
	}
	//dc_dragsequence(stack, longest);
	return (longest);
}

void	dc_filtersorted(t_streak	**longest)
{
	t_list	*temp;
	t_list	*last_next;

	temp = (*longest)->first;
	last_next = (*longest)->last->next;
	(*longest)->last->next = NULL;
	while (temp)
	{
		temp->op[0] = INT_MAX;
		temp->op[1] = INT_MAX;
		temp = temp->next;
	}
	(*longest)->last->next = last_next;
}
