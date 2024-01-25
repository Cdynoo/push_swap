/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reform_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 05:18:49 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/25 05:18:51 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	char	*fullinput;
	char	**strings_arr;

	i = 1;
	len = argc;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	fullinput = (char *)ft_calloc(len, sizeof(char));
	i = 1;
	while (i < argc)
	{
		fullinput = ft_strjoin(fullinput, argv[i++]);
		fullinput = ft_strjoin(fullinput, " ");
	}
	strings_arr = ft_split(fullinput, ' ');
	init(argc, strings_arr);
	ft_del(strings_arr, argc - 1);
	return (0);
}
