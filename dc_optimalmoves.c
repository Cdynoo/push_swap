/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_optimalmoves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:05:18 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/17 10:05:20 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*dc_findneighbour_inb(t_list **stack, t_list *newnode)
{
	t_list	*temp;
	t_list	*maxnode;

	maxnode = dc_get_max(stack);
	temp = maxnode;
	if (temp && newnode)
	{
		if (dc_edge(stack, newnode))
			return (maxnode);
		while (temp && (temp->next != maxnode) && (temp->num > newnode->num))
			temp = temp->next;
	}
	return (temp);
}

static t_list	*dc_findneighbour_ina(t_list **stack, t_list *newnode)
{
	t_list	*temp;
	t_list	*minnode;

	minnode = dc_get_min(stack);
	temp = minnode;
	if (temp && newnode)
	{
		if (dc_edge(stack, newnode))
			return (minnode);
		while (temp && (temp->next != minnode) && (temp->num < newnode->num))
			temp = temp->next;
	}
	return (temp);
}

void	dc_req(t_list **stack_a, t_list *node, t_list **stack_b)
{
	int		min_index;
	t_list	*neighbour;

	if (stack_a && stack_b && node && node->op)
	{
		neighbour = NULL;
		ft_memset(node->op, 0, 12 * sizeof(int));
		node->op[0] = dc_num_rot(node, *stack_a);
		node->op[1] = dc_num_revrot(node, *stack_a);
		neighbour = dc_findneighbour_inb(stack_b, node);
		node->op[2] = dc_num_rot(neighbour, *stack_b);
		node->op[3] = dc_num_revrot(neighbour, *stack_b);
		min_index = node->op[1] < node->op[0];
		node->op[6 + min_index] = node->op[min_index];
		min_index = node->op[3] < node->op[2];
		node->op[8 + min_index] = node->op[2 + min_index];
	}
}

static void	dc_reqto_a(t_list **stack_a, t_list *node, t_list **stack_b)
{
	int		min_index;
	t_list	*neighbour;

	if (stack_a && stack_b && node && node->op)
	{
		neighbour = NULL;
		ft_memset(node->op, 0, 12 * sizeof(int));
		node->op[2] = dc_num_rot(node, *stack_a);
		node->op[3] = dc_num_revrot(node, *stack_a);
		neighbour = dc_findneighbour_ina(stack_b, node);
		node->op[0] = dc_num_rot(neighbour, *stack_b);
		node->op[1] = dc_num_revrot(neighbour, *stack_b);
		min_index = node->op[1] < node->op[0];
		node->op[6 + min_index] = node->op[min_index];
		min_index = node->op[3] < node->op[2];
		node->op[8 + min_index] = node->op[2 + min_index];
	}
}

void	dc_possiblemovesto_a(t_list **stack_a, t_list **stack_b)
{
	int		len;
	t_list	*node;

	if (stack_a)
	{
		node = (*stack_a);
		len = dc_count(stack_a);
		while (len)
		{
			len--;
			dc_reqto_a(stack_a, node, stack_b);
			node = node->next;
		}
	}
}
