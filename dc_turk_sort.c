/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:17:03 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/20 03:17:06 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	dc_sort(t_list	*stack_a, long *arr, int len)
{
	t_list		*stack_b;

	stack_b = NULL;
	if (stack_a)
	{
		dc_indexit(&stack_a, arr, len);
		testm(&stack_a, &stack_b);
	}
}