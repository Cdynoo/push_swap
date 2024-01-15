/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:56:29 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/02 07:56:32 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	dc_rotate(t_list **lst, char *str)
{
	if (lst && *lst && (dc_count(lst) > 1))
	{
		(*lst) = (*lst)->next;
		write(1, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	dc_rr(t_list **stack_a, t_list **stack_b)
{
	if ((dc_count(stack_a) > 1) && (dc_count(stack_b) > 1))
	{
		if (dc_rotate(stack_a, "r") && dc_rotate(stack_b, "r\n"))
			return (1);
	}
	return (0);
}

int	dc_reverse_rot(t_list **lst, char *str)
{
	if (lst && *lst && (dc_count(lst) > 1))
	{
		(*lst) = (*lst)->prev;
		write(1, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	dc_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((dc_count(stack_a) > 1) && (dc_count(stack_b) > 1))
	{
		if (dc_reverse_rot(stack_a, "rr") && dc_reverse_rot(stack_b, "r\n"))
			return (1);
	}
	return (0);
}

void	dc_rot_or_rev(t_list **stack, int rotations)
{
	int			len;

	len = dc_count(stack);
	if (rotations <= (len - rotations))
		dc_rotate(stack, "ra\n");
	else
		dc_reverse_rot(stack, "rra\n");
}
