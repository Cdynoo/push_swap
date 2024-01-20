/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 04:36:31 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/01 04:36:34 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(long *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

void	sort_list(long *arr, int len)
{
	int		i;
	long	temp;
	int		swaped;

	i = 1;
	swaped = 1;
	while (swaped == 1)
	{
		i = 0;
		swaped = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swaped = 1;
			}
			i++;
		}
	}
}

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (len-- > 0)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (ptr);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;
	int		n_bytes;

	n_bytes = nitems * size;
	if (nitems != 0 && n_bytes / nitems != size)
		return (0);
	res = malloc(n_bytes);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, n_bytes);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}
