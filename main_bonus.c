/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:03:10 by olmohame          #+#    #+#             */
/*   Updated: 2024/02/01 12:03:16 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	spaces(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

static int	calc_length(int argc, char **argv, int *len)
{
	int	i;

	i = 1;
	*len = argc;
	while (i < argc && ft_strlen(argv[i]) && !spaces(argv[i]))
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

	if (calc_length(argc, argv, &len) != argc)
		return (0);
	fullinput = (char *)ft_calloc(len, sizeof(char));
	if (!fullinput)
		return (0);
	i = 1;
	while (i < argc)
	{
		ft_strlcat(fullinput, argv[i++], len);
		ft_strlcat(fullinput, " ", len);
	}
	strings_arr = ft_split(fullinput, ' ');
	if (strings_arr)
	{
		i = ft_count(fullinput, ' ');
		validate(i, strings_arr);
		ft_del(strings_arr, i);
	}
	free(fullinput);
	return (0);
}
