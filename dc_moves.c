/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 02:44:32 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/02 02:44:34 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	dc_swap(t_list **lst, char *str)
{
	long	temp;
	int		index;

	if (lst && *lst && str && (dc_count(lst) > 1))
	{
		temp = (*lst)->num;
		index = (*lst)->i;
		(*lst)->num = (*lst)->next->num;
		(*lst)->i = (*lst)->next->i;
		(*lst)->next->num = temp;
		(*lst)->next->i = index;
		write(1, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	dc_ss(t_list **stack_a, t_list **stack_b)
{
	if ((dc_count(stack_a) > 1) && (dc_count(stack_b) > 1))
	{
		if (dc_swap(stack_a, "s") && dc_swap(stack_b, "s\n"))
			return (1);
	}
	return (0);
}

int	dc_push(t_list **from, t_list **to, char *str)
{
	t_list	*node;

	if (from && *from && str && dc_count(from) && to)
	{
		node = dc_pop(from);
		dc_add_front(to, node);
		if (node)
		{
			write(1, str, ft_strlen(str));
			return (1);
		}
	}
	return (0);
}

int	dc_num_rot(t_list *from, t_list *to)
{
	int		rot_count;

	rot_count = INT_MAX;
	if (from && to)
	{
		rot_count = 0;
		while (to->num != from->num)
		{
			from = from->prev;
			rot_count++;
		}
	}
	return (rot_count);
}

int	dc_num_revrot(t_list *from, t_list *to)
{
	int		count;

	count = INT_MAX;
	if (from && to)
	{
		count = 0;
		while (to->num != from->num)
		{
			from = from->next;
			count++;
		}
	}
	return (count);
}
