/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:55:38 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/31 10:55:40 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	dc_swap_t(t_list **lst, char *str, int test)
{
	long	temp;
	int		index;

	if (lst && *lst && (dc_count(lst) > 1))
	{
		temp = (*lst)->num;
		index = (*lst)->i;
		(*lst)->num = (*lst)->next->num;
		(*lst)->i = (*lst)->next->i;
		(*lst)->next->num = temp;
		(*lst)->next->i = index;
		if (test)
			write(1, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	dc_ss_t(t_list **stack_a, t_list **stack_b, int test)
{
	if ((dc_count(stack_a) > 1) && (dc_count(stack_b) > 1))
	{
		if (dc_swap_t(stack_a, "s", test) && dc_swap_t(stack_b, "s\n", test))
			return (1);
	}
	return (0);
}

int	dc_push_t(t_list **from, t_list **to, char *str, int test)
{
	t_list	*node;

	if (from && *from && dc_count(from) && to)
	{
		node = dc_pop(from);
		dc_add_front(to, node);
		if (node)
		{
			if (test)
				write(1, str, ft_strlen(str));
			return (1);
		}
	}
	return (0);
}
