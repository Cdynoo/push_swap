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
	{
		if (ft_strncmp(split_op[i], inst, ft_strlen(inst)) == 0)
		{
			ft_del(split_op, 11);
			return (i);
		}
		i++;
	}
	ft_del(split_op, 11);
	return (-1);
}

static int	doop(t_list **stack_a, t_list **stack_b, int index, char *inst)
{
	int	test;
	int	(*single_stack[3])(t_list **stack, char *str, int);
	int	(*double_stacks[3])(t_list **, t_list **, int);

	test = 0;
	single_stack[0] = dc_swap_t;
	single_stack[1] = dc_rotate_t;
	single_stack[2] = dc_reverse_rot_t;
	double_stacks[0] = dc_ss_t;
	double_stacks[1] = dc_rr_t;
	double_stacks[2] = dc_rrr_t;
	if (index < 6)
		return ((*single_stack[index / 2])(stack_a, inst, test));
	else if (index > 7)
		return ((*double_stacks[index - 8])(stack_a, stack_b, test));
	return (dc_push_t(stack_b, stack_a, inst, test));
}

static int	apply_inst(t_list **stack_a, t_list **stack_b, char *inst)
{
	int	index;

	index = validate_op(inst);
	if (index > -1)
	{
		if (inst[ft_strlen(inst) - 2] == 'b')
			doop(stack_b, stack_a, index, inst);
		else
			doop(stack_a, stack_b, index, inst);
		return (1);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}

static void	show_result(t_list **stack_a, t_list **stack_b, char *inst, int pre)
{
	if (pre)
	{
		if (!inst)
			write(1, "KO\n", 3);
	}
	else if (!inst)
	{
		if (dc_issorted(stack_a) && !dc_count(stack_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	if (inst)
	{
		free(inst);
		inst = NULL;
	}
}

void	dc_testsort(t_list	*stack_a, long *arr, int len)
{
	t_list		*stack_b;
	char		*inst;
	int			presorted;

	stack_b = NULL;
	stack_a = dc_build_list(arr, len);
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		inst = get_next_line(0);
		presorted = dc_issorted(&stack_a);
		presorted = presorted && inst;
		while (inst && apply_inst(&stack_a, &stack_b, inst))
		{
			free(inst);
			inst = get_next_line(0);
		}
		show_result(&stack_a, &stack_b, inst, presorted);
		dc_clear(&stack_a);
		dc_clear(&stack_b);
	}
}
