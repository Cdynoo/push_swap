/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:32:32 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/31 07:32:35 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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

static int	validate(int argc, char **argv)
{
	int		i;
	long	*list_a;
	t_list	*stack_a;

	i = -1;
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
	//if (!ls_is_sorted(list_a, argc))
	//{
		stack_a = dc_build_list(list_a, argc);
		dc_testsort(stack_a, list_a, argc);
	//}
	free(list_a);
	return (0);
}

static int	emp(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

static int	v(int argc, char **argv, int *len)
{
	int	i;

	i = 1;
	*len = argc;
	while (i < argc && ft_strlen(argv[i]) && !emp(argv[i]))
		*len += ft_strlen(argv[i++]);
	if (i != argc)
		write(2, "Error\n", 6);
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	char	*fullinput;
	char	**strings_arr;

	if (v(argc, argv, &len) != argc)
		return (0);
	fullinput = (char *)ft_calloc(len, sizeof(char));
	i = 1;
	while (i < argc)
	{
		ft_strlcat(fullinput, argv[i++], len);
		ft_strlcat(fullinput, " ", len);
	}
	strings_arr = ft_split(fullinput, ' ');
	i = 0;
	while (strings_arr[i])
		i++;
	validate(i, strings_arr);
	free(fullinput);
	ft_del(strings_arr, i);
	return (0);
}
