/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_rotations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:58:11 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/31 10:58:24 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	dc_rotate_t(t_list **lst, char *str, int test)
{
	if (lst && *lst && (dc_count(lst) > 1))
	{
		(*lst) = (*lst)->next;
		if (test)
			write(1, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	dc_rr_t(t_list **stack_a, t_list **stack_b, int test)
{
	if ((dc_count(stack_a) > 1) && (dc_count(stack_b) > 1))
	{
		if (dc_rotate_t(stack_a, "r", test) \
					&& dc_rotate_t(stack_b, "r\n", test))
			return (1);
	}
	return (0);
}

int	dc_reverse_rot_t(t_list **lst, char *str, int test)
{
	if (lst && *lst && (dc_count(lst) > 1))
	{
		(*lst) = (*lst)->prev;
		if (test)
			write(1, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	dc_rrr_t(t_list **stack_a, t_list **stack_b, int test)
{
	if ((dc_count(stack_a) > 1) && (dc_count(stack_b) > 1))
	{
		if (dc_reverse_rot_t(stack_a, "rr", test) \
					&& dc_reverse_rot_t(stack_b, "r\n", test))
			return (1);
	}
	return (0);
}
