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

static int	dc_edge(t_list **stack, t_list *node)
{
	int		maximum;
	int		minimum;
	t_list	*temp;

	maximum = 1;
	minimum = 1;
	(*stack)->prev->next = NULL;
	temp = *stack;
	while (temp)
	{
		if (temp->num < node->num)
			minimum = 0;
		if (temp->num > node->num)
			maximum = 0;
		temp = temp->next;
	}
	printf("[%ld] Is min {%d}, Is max {%d}\n", node->num, minimum, maximum);
	(*stack)->prev->next = *stack;
	if (minimum || maximum)
		return (1);
	return (0);
}

static t_list	*dc_get_max(t_list **stack)
{
	t_list	*temp;
	t_list	*maxnode;

	(*stack)->prev->next = NULL;
	temp = *stack;
	maxnode = NULL;
	while (temp)
	{
		if (!maxnode || temp->num > maxnode->num)
			maxnode = temp;
		temp = temp->next;
	}
	(*stack)->prev->next = *stack;
	return (maxnode);
}

static t_list	*dc_findneighbour(t_list **stack, t_list *newnode)
{
	t_list	*temp;
	t_list	*maxnode;

	maxnode = dc_get_max(stack);
	temp = maxnode;
	if (dc_edge(stack, newnode))
		return (maxnode);
	while (temp && (temp->next != maxnode) && (temp->num > newnode->num))
		temp = temp->next;
	return (temp);
}

static void	dc_req(t_list **stack_a, t_list *node, t_list **stack_b)
{
	t_list	*neighbour;

	neighbour = NULL;
	printf("working on {%ld}\n", (node)->num);
	node->op[0] = dc_num_rot(node, *stack_a);
	node->op[1] = dc_count_revrot(node, *stack_a);
	neighbour = dc_findneighbour(stack_b, node);
	printf("Neighbour is {%ld}\n\n", (neighbour)->num);
	node->op[2] = dc_num_rot(neighbour, *stack_b);
	node->op[3] = dc_count_revrot(neighbour, *stack_b);
}

void	dc_possiblemoves(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = *stack_a;
	while (node->next != *stack_a)
	{
		dc_req(stack_a, node, stack_b);
		node = node->next;
	}
	dc_req(stack_a, node, stack_b);
}

void	testm(t_list **stack_a, t_list **stack_b)
{
	dc_push(stack_a, stack_b, "pb\n");
	dc_push(stack_a, stack_b, "pb\n");
	dc_push(stack_a, stack_b, "pb\n");
	//dc_push(stack_a, stack_b, "pb\n");
	//dc_push(stack_a, stack_b, "pb\n");
	dc_possiblemoves(stack_a, stack_b);

	t_list	*node;

	(*stack_a)->prev->next = NULL;
	node = *stack_a;
	while (node)
	{
		printf("Node {%ld}, rot_a {%d}, revrot_a {%d}, rot_b {%d}, revrot_b {%d}\n", node->num, node->op[0], node->op[1], node->op[2], node->op[3]);
		node = node->next;
	}
	(*stack_a)->prev->next = *stack_a;
}
