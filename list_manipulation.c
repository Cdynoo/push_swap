/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 05:37:08 by olmohame          #+#    #+#             */
/*   Updated: 2024/01/01 05:37:10 by olmohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*dc_new_node(long number, int index)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->prev = node;
	node->next = node;
	node->num = number;
	node->i = index;
	return (node);
}

void	dc_add_back(t_list **lst, t_list *newnode)
{
	if (lst && !*lst && newnode)
		*lst = newnode;
	else if (lst && newnode)
	{
		(*lst)->prev->next = newnode;
		newnode->prev = (*lst)->prev;
		newnode->next = *lst;
		(*lst)->prev = newnode;
	}
}

void	dc_add_front(t_list **lst, t_list *newnode)
{
	if (lst && !*lst && newnode)
		*lst = newnode;
	else if (lst && newnode)
	{
		dc_add_back(lst, newnode);
		*lst = newnode;
	}
}

t_list	*dc_pop(t_list **lst)
{
	int		index;
	long	number;
	t_list	*temp;

	if (lst && *lst)
	{
		index = (*lst)->i;
		number = (*lst)->num;
		temp = (*lst)->next;
		if ((*lst)->next == (*lst))
			temp = NULL;
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		free(*lst);
		*lst = temp;
		return (dc_new_node(number, index));
	}
	return (NULL);
}

void	dc_clear(t_list **lst)
{
	t_list	*temp;

	if (lst && *lst)
	{
		(*lst)->prev->next = NULL;
		while (*lst)
		{
			temp = *lst;
			(*lst) = (*lst)->next;
			free(temp);
			temp = NULL;
		}
	}
}
