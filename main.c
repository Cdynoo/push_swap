/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 22:48:46 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/01 01:03:15 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_duplicate(long *list_a, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
	{
		if (list_a[i] == list_a[len - 1])
			return (1);
	}
	return (0);
}

static int	detect_flow(long num, int dig, int sign)
{
	if (num > INT_MAX / 10)
		return (1);
	else if (num * 10 > (INT_MAX - dig + sign))
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	read_num(const char *start, long *field)
{
	int	i;
	int	track_sign;

	i = 0;
	track_sign = 0;
	while (start[i] == '+' || start[i] == '-')
	{
		if (start[i] == '-')
			track_sign++;
		i++;
	}
	while (start[i] && ft_isdigit(start[i]))
	{
		if (detect_flow(*field, start[i] - '0', track_sign))
			return (0);
		else
			*field = *field * 10 + start[i++] - '0';
	}
	if (start[i] || !ft_isdigit(start[i - 1]))
		return (0);
	if (track_sign)
		*field *= -1;
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	long	*list_a;
	t_list	*stack_a;

	i = 0;
	list_a = ft_calloc((argc - 1), sizeof(long));
	if (!list_a)
		return (0);
	while (++i < argc)
	{
		if (!read_num(argv[i], &list_a[i - 1]) || is_duplicate(list_a, i))
		{
			free(list_a);
			list_a = NULL;
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (!is_sorted(list_a, argc - 1))
	{
		stack_a = dc_build_list(list_a, argc - 1);
		dc_sort(stack_a, list_a, argc - 1);
	}
	free(list_a);
	return (0);
}
