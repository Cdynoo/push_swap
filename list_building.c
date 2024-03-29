/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 04:40:17 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/02 04:40:19 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*dc_build_list(long *list_a, int len)
{
	int		i;
	t_list	*start;

	i = -1;
	start = NULL;
	if (list_a)
	{
		while (++i < len)
			dc_add_back(&start, dc_new_node(list_a[i], 0));
		if (dc_count(&start) != len)
			dc_clear(&start);
	}
	return (start);
}

int	dc_count(t_list **lst)
{
	t_list	*temp;
	int		count;

	count = 0;
	if (lst && *lst)
	{
		count++;
		temp = *lst;
		while (temp->next != *lst)
		{
			count++;
			temp = temp->next;
		}
	}
	return (count);
}

int	dc_issorted(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (lst && *lst)
	{
		temp = *lst;
		while (temp->next != *lst)
		{
			if (temp->i + 1 != temp->next->i)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

int	dc_issubsorted(t_list **lst)
{
	if (lst && *lst)
	{
		if (dc_count(lst) == 2)
			return (((*lst)->i < (*lst)->next->i));
		return (((*lst)->i < (*lst)->next->i) && \
		((*lst)->next->i < (*lst)->next->next->i));
	}
	return (0);
}
