/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:37:53 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/07 04:37:55 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_streak	*dc_new_streak(t_list *stack)
{
	t_streak	*streak;

	streak = malloc(sizeof(t_streak));
	if (!streak)
		return (NULL);
	streak->first = stack;
	streak->last = stack;
	streak->len = 1;
	return (streak);
}

static void	dc_reset(t_streak *longest, t_streak *curr, t_list *node, int c)
{
	if (!c)
	{
		curr->last = node->next;
		curr->len = curr->len + 1;
	}
	if (curr->len >= longest->len)
	{
		longest->first = curr->first;
		longest->last = curr->last;
		longest->len = curr->len;
	}
	if (c)
	{
		curr->first = node->next;
		curr->last = node->next;
		curr->len = 1;
	}
}

t_streak	*dc_longeststreak(t_list **stack)
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
			if ((temp->i + 1) == temp->next->i)
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
	}
	return (longest);
}

static t_streak	*dc_laststreak(t_list **stack)
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
			if ((temp->i - 1) == temp->prev->i)
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

t_streak	*dc_cyclestreak(t_list **stack)
{
	t_list		*temp;
	t_streak	*b_longest;

	b_longest = NULL;
	if (stack && *stack)
	{
		b_longest = dc_laststreak(stack);
		temp = b_longest->last;
		while (1)
		{
			if ((temp->i + 1) == temp->next->i)
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
