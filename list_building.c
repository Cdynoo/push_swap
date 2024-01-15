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

void	dc_show(t_list **lst)
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		printf("%ld, ", temp->num);
		while (temp->next != *lst)
		{
			printf("%ld, ", temp->next->num);
			temp = temp->next;
		}
		printf("\n");
	}
}

int	dc_issorted(t_list **lst, int len)
{
	t_list	*temp;

	temp = NULL;
	if (lst && *lst)
	{
		temp = *lst;
		while (temp->next != *lst)
		{
			if ((temp->i + 1)%len != temp->next->i)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

int	dc_asorted(t_list **lst)
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

t_list	*dc_build_list(long *list_a, int len)
{
	int		i;
	t_list	*start;

	i = -1;
	start = NULL;
	while (++i < len)
		dc_add_back(&start, dc_new_node(list_a[i], 0));
	if (dc_count(&start) != len)
		dc_clear(&start);
	return (start);
}
