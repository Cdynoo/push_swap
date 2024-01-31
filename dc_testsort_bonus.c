/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_testsort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:31:04 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/31 07:31:23 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	validate_op(char *inst)
{
	int		i;
	char	*op;
	char	**split_op;

	op = "sa\n sb\n ra\n rb\n rra\n rrb\n pa\n pb\n ss\n rr\n rrr\n";
	split_op = ft_split(op, ' ');
	i = 0;
	while (split_op[i])
		i++;
	i = 0;
	while (split_op[i])
	{
		if (ft_strncmp(split_op[i], inst, ft_strlen(inst)) == 0)
		{
			ft_del(split_op, i);
			return (i);
		}
		i++;
	}
	ft_del(split_op, i);
	return (-1);
}

static int	apply_op(t_list **stack_a, t_list **stack_b, char *inst)
{
	int	index;

	index = validate_op(inst);
	if (index > -1)
	{
		printf("valid inst\n");
		return (1);
	}
	else
		printf("Not valid inst\n");
	return (0);
}

void	dc_testsort(t_list	*stack_a, long *arr, int len)
{
	t_list		*stack_b;
	char		*inst;

	stack_b = NULL;
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		inst = get_next_line(0);
		if (inst && dc_issorted(&stack_a))
			printf("KO\n");
		//printf("%s", inst);
		apply_op(&stack_a, &stack_b, inst);
		//if (dc_count(&stack_a) > 3)
		//	movefromAtoB(&stack_a, &stack_b, len);
		//init_sort(&stack_a);
		//movefromBtoA(&stack_b, &stack_a);
		//dc_arrange(&stack_a, dc_get_min(&stack_a));
		/*if (dc_issorted(&stack_a))
			printf("OK\n");
		else
			printf("KO\n");
		printf("A: ");
		dc_show(&stack_a);
		printf("B: ");
		dc_show(&stack_b);*/
		dc_clear(&stack_a);
	}
}
