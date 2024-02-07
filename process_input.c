/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:06:05 by olmohame          #+#    #+#             */
/*   Updated: 2024/02/01 12:06:08 by olmohame         ###   ########.fr       */
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
	else if (dig && (num * 10 > (INT_MAX - dig + sign)))
		return (1);
	return (0);
}

static int	read_num(const char *start, long *field)
{
	int	i;
	int	track_sign;

	if (start == NULL)
		return (0);
	i = 0;
	track_sign = 0;
	if (start[i] == '+' || start[i] == '-')
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

int	validate(int argc, char **argv)
{
	int		i;
	long	*list_a;
	t_list	*stack_a;

	i = -1;
	stack_a = NULL;
	if (!argv)
		return (0);
	list_a = ft_calloc((argc), sizeof(long));
	if (!list_a)
		return (0);
	while (++i < argc)
	{
		if (!read_num(argv[i], &list_a[i]) || is_duplicate(list_a, i + 1))
		{
			free(list_a);
			list_a = NULL;
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (!ls_is_sorted(list_a, argc))
		dc_sort(stack_a, list_a, argc);
	free(list_a);
	return (0);
}
