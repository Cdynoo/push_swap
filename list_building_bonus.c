/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_building_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:15:35 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/31 10:15:37 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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
