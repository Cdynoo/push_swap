/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 04:36:31 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/01 04:36:34 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ls_sort_list(long *arr, int len)
{
	int		i;
	long	temp;
	int		swaped;

	i = 1;
	swaped = 1;
	if (arr)
	{
		while (swaped == 1)
		{
			i = 0;
			swaped = 0;
			while (i < len - 1)
			{
				if (arr[i] > arr[i + 1])
				{
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					swaped = 1;
				}
				i++;
			}
		}
	}
}

static int	match(long *list_a, int len, long num)
{
	int	i;

	i = -1;
	if (list_a)
	{
		while (++i < len)
		{
			if (list_a[i] == num)
				return (i);
		}
	}
	return (-1);
}

void	dc_indexit(t_list	**lst, long *arr, int len)
{
	t_list	*temp;

	ls_sort_list(arr, len);
	temp = NULL;
	if (lst && *lst && arr)
	{
		(*lst)->prev->next = NULL;
		temp = *lst;
		while (temp)
		{
			temp->i = match(arr, len, temp->num);
			temp = temp->next;
		}
		(*lst)->prev->next = *lst;
	}
}

int	ls_is_sorted(long *arr, int len)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (++i < len - 1)
		{
			if (arr[i] > arr[i + 1])
				return (0);
		}
		return (1);
	}
	return (0);
}
