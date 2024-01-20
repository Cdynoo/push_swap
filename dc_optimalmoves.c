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
	(*stack)->prev->next = *stack;
	if (minimum || maximum)
		return (1);
	return (0);
}

static t_list	*dc_findneighbour(t_list **stack, t_list *newnode)
{
	t_list	*temp;

	(*stack)->prev->next = NULL;
	temp = *stack;
	if (temp->num < temp->next->num)
		temp = temp->next;
	while (temp && (temp->num > newnode->num))
		temp = temp->next;
	/*while (temp)
	{
		if (temp->num < newnode->num)
			break ;
		temp = temp->next;
	}*/
	(*stack)->prev->next = *stack;
	if (temp->num < newnode->num)
		return (temp);
	return (temp);
}

static void	dc_req(t_list **stack_a, t_list *node, t_list **stack_b)
{
	t_list	*neighbour;

	printf("working on {%ld}\n", (node)->num);
	node->op[0] = dc_num_rot(node, *stack_a);
	node->op[1] = dc_count_revrot(node, *stack_a);
	if (!dc_edge(stack_b, node))
	{
		neighbour = dc_findneighbour(stack_b, node);
		printf("Neighbour is {%ld}\n\n", (neighbour)->num);
		node->op[2] = dc_num_rot(neighbour, *stack_b);
		node->op[3] = dc_count_revrot(neighbour, *stack_b);
	}
	else if ((*stack_b)->num < (*stack_b)->next->num)
	{
		printf("go to top, after rotate\n\n");
		node->op[2] = 1;
	}
	else
		printf("NO rotate\n\n");
}

void	dc_possiblemoves(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	//(*stack_a)->prev->next = NULL;
	printf("A: ");
	dc_show(stack_a);
	printf("B: ");
	dc_show(stack_b);
	node = *stack_a;
	while (node->next != *stack_a)
	{
		dc_req(stack_a, node, stack_b);
		node = node->next;
	}
	dc_req(stack_a, node, stack_b);
	//(*stack_a)->prev->next = *stack_a;
}

void	testm(t_list **stack_a, t_list **stack_b)
{
	dc_push(stack_a, stack_b, "pb\n");
	dc_push(stack_a, stack_b, "pb\n");
	dc_push(stack_a, stack_b, "pb\n");
	dc_push(stack_a, stack_b, "pb\n");
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
