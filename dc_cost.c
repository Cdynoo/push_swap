/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:44:04 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/30 09:44:06 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sum(int *op)
{
	int	i;
	int	count;

	i = 6;
	count = 0;
	if (op)
	{
		while (i)
			count += op[--i];
	}
	return (count);
}

static void	zeromoves(t_list *node, int start)
{
	if (node && node->op && start > -1)
	{
		node->op[start] = 0;
		node->op[start + 2] = 0;
		node->op[start + 4] = 0;
	}
}

static int	reduce(t_list	*node, int start)
{
	if (node && node->op && start > -1)
	{
		while (node->op[start] > 0 && node->op[start + 2] > 0)
		{
			node->op[start]--;
			node->op[start + 2]--;
			node->op[start + 4]++;
		}
		return (node->op[start] + node->op[start + 2] + node->op[start + 4]);
	}
	return (INT_MAX);
}

void	opttrim(t_list **stack)
{
	int		len;
	t_list	*node;

	if (stack && *stack)
	{
		node = (*stack);
		len = dc_count(stack);
		while (len-- && node && node->op)
		{
			zeromoves(node, reduce(node, 0) < reduce(node, 1));
			if (sum(node->op) > sum(node->op + 6))
			{
				ft_memset(node->op, 0, 6 * sizeof(int));
				node->op[0] = node->op[6];
				node->op[1] = node->op[7];
				node->op[2] = node->op[8];
				node->op[3] = node->op[9];
			}
			node = node->next;
		}
	}
}

t_list	*dc_get_mincost(t_list **stack)
{
	int		len;
	t_list	*temp;
	t_list	*minnode;

	minnode = NULL;
	if (stack && *stack)
	{
		temp = *stack;
		len = dc_count(stack);
		while (len--)
		{
			if (!minnode || sum(temp->op) < sum(minnode->op))
				minnode = temp;
			temp = temp->next;
		}
	}
	return (minnode);
}
