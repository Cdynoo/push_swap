/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_movenode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 04:20:09 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/11 04:20:12 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*dc_findnext(t_list *needle, t_list **haystack, int len)
{
	int		size;
	t_list	*temp;

	temp = *haystack;
	size = dc_count(haystack);
	//printf("%d\n", len);
	while (size-->=0)
	{
		if (!((needle->i + 1) % len - temp->i))
			return (temp);
		else if (!((temp->i + 1) % len - needle->i))
			return (temp);
		//dc_show(&temp);
		temp = temp->next;
	}
	return (NULL);
}

static int	dc_optimoves(t_list **stack, int rotations)
{
	int			len;

	len = dc_count(stack);
	if (rotations <= (len - rotations))
		return (rotations);
	else
		return (len - rotations);
}
void	dc_rot_or_revb(t_list **stack, int rotations)
{
	int	len;
	int	rev;

	len = dc_count(stack);
	rev = (len - rotations);
	if (rotations <= (len - rotations))
		while (rotations--)
			dc_rotate(stack, "rb\n");
	else
		while (rev--)
			dc_reverse_rot(stack, "rrb\n");
}

void	dc_movenode(t_list **stack_a, t_list **stack_b, int len)
{
	int		top_moves;
	int		bottom_moves;
	t_list	*nexttop;
	t_list	*nextbottom;

	//printf("\n\n");
	top_moves = len;
	bottom_moves = len;
	nexttop = dc_findnext(*stack_a, stack_b, len);
	top_moves = dc_optimoves(stack_b, dc_num_rot(nexttop, *stack_b));
	nextbottom = dc_findnext((*stack_a)->prev, stack_b, len);
	bottom_moves = dc_optimoves(stack_b, dc_num_rot(nextbottom, *stack_b)) + 1;
	if (top_moves <= bottom_moves)
	{
		//printf("putting top %ld, in %d moves\n", nexttop->num, top_moves);
		dc_rot_or_revb(stack_b, dc_num_rot(nexttop, *stack_b));
	}
	else
	{
		dc_rot_or_revb(stack_b, dc_num_rot(nextbottom, *stack_b));
		//printf("putting bottom %ld, in %d moves\n", nextbottom->num, bottom_moves);
		//dc_rotate(stack_a, "raa\n");
	}
	dc_push(stack_b, stack_a, "pa\n");
	if (top_moves > bottom_moves)
		dc_rotate(stack_a, "ra\n");
	//printf("finished moves to a\n");
}
