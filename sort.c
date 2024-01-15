/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:11:56 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/03 05:11:58 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

static void	dc_indexit(t_list	**lst, long *arr, int len)
{
	t_list	*temp;

	sort_list(arr, len);
	temp = NULL;
	if (lst && *lst)
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

void	dc_sort(t_list	*stack_a, long *arr, int len)
{
	t_list		*stack_b;
	t_streak	*longest;
	//t_list		*nexttop;

	stack_b = NULL;
	longest = NULL;
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		//longest = dc_laststreak(&stack_a);
		//printf("CY STREAK: %ld, %ld, %d\n", longest->first->num, longest->last->num, longest->len);
		longest = dc_getstreak(&stack_a);
		//if (longest)
		//	printf("STREAK: %ld, %ld, %d\n", longest->first->num, longest->last->num, longest->len);
		while (longest->last->num != ((stack_a)->prev->num))
		{
			printf("I shouldn't be able to see this\n");
			if (((stack_a)->i) == ((stack_a)->next->i + 1))
			{
				dc_swap(&stack_a, "sa\n");
				//dc_show(&stack_a);
			}
			dc_rot_or_rev(&stack_a, dc_num_rot(longest->last, (stack_a)->prev));
			//dc_show(&stack_a);
		}
		//printf("longesgt last, head is %ld\n", (stack_a)->num);
		while (!dc_issorted(&stack_a, len))
		{
			if (dc_updatestreak(&stack_a))
				continue ;
			if (((stack_a)->i) == ((stack_a)->next->i + 1))
			{
				dc_swap(&stack_a, "sa\n");
				//dc_show(&stack_a);
				continue ;
			}
			if (((stack_a)->i - 1) == ((stack_a)->prev->i))
			{
				dc_rotate(&stack_a, "ra\n");
				//dc_show(&stack_a);
				continue ;
			}
			//dc_updatestreak(&stack_a);
			if (!dc_issorted(&stack_a, len))
			{
				dc_push(&stack_a, &stack_b, "pb\n");
				//dc_show(&stack_a);
			}
		}
		//printf("push to a\n");
		while (dc_count(&stack_b))
		{
			/*if (stack_a)
			{
				printf("A: ");
				dc_show(&stack_a);
			}
			if (stack_b)
			{
				printf("B: ");
				dc_show(&stack_b);
			}*/
			dc_movenode(&stack_a, &stack_b, len);
			if (((stack_a)->i - 1) == ((stack_a)->prev->i))
			{
				dc_rotate(&stack_a, "ra\n");
			}
		}
		//printf("Head is %ld, i %d\n", (stack_a)->num, (stack_a)->i);
		dc_updatestreak(&stack_a);
		/*if (stack_a)
		{
			printf("A: ");
			dc_show(&stack_a);
		}
		if (stack_b)
		{
			printf("B: ");
			dc_show(&stack_b);
		}*/
		dc_clear(&stack_b);
		dc_clear(&stack_a);
		free(longest);
	}
}
