/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 08:07:44 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/07 08:07:46 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	dc_dragstreak(t_list **stack, t_streak	*longest)
{
	while (longest->last->num != ((*stack)->prev->num))
	{
		if (((*stack)->i) == ((*stack)->next->i + 1))
		{
			dc_swap(stack, "sa\n");
			//dc_show(stack);
		}
		dc_rot_or_rev(stack, dc_num_rot(longest->last, (*stack)->prev));
		//dc_show(stack);
	}
}

t_streak	*dc_getstreak(t_list **stack)
{
	t_streak	*longest;
	t_streak	*cyclic_streak;

	longest = dc_longeststreak(stack);
	cyclic_streak = dc_cyclestreak(stack);
	if (cyclic_streak->len >= longest->len)
	{
		free(longest);
		longest = cyclic_streak;
	}
	dc_dragstreak(stack, longest);
	return (longest);
}

int	dc_updatestreak(t_list **stack)
{
	t_streak	*longest;
	long		prevhead;

	prevhead = (*stack)->num;
	longest = dc_getstreak(stack);
	if (longest)
		free(longest);
	if (prevhead != (*stack)->num)
		return (1);
	return (0);
}
