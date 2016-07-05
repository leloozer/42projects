/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:30:42 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 11:03:38 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_sortsize2(t_file *new, t_file *list)
{
	while (list->next && new->size < list->size)
		list = list->next;
	if (list->next && new->size == list->size)
	{
		while (list->next && new->size == list->size &&
				(ft_strcmp(new->name, list->name) > 0))
			list = list->next;
	}
	return (list);
}

t_file	*ft_sortsize(t_file *new, t_file *list)
{
	if (list == NULL)
	{
		list = new;
		return (list);
	}
	if (new->size > list->size)
		list = ft_pushfront(new, list);
	else
	{
		list = ft_sortsize2(new, list);
		if (list->prev == NULL)
		{
			list->prev = new;
			new->next = list;
			list = new;
			return (list);
		}
		list = ft_insertlist(list, new);
	}
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}

t_file	*ft_sortsizerev2(t_file *new, t_file *list)
{
	while (list->next && new->size > list->size)
		list = list->next;
	if (list->next && new->size == list->size)
	{
		while (list->next && new->size == list->size &&
				(ft_strcmp(new->name, list->name) < 0))
			list = list->next;
	}
	return (list);
}

t_file	*ft_sortsizerev(t_file *new, t_file *list)
{
	if (list == NULL)
	{
		list = new;
		return (list);
	}
	if (new->size < list->size)
		list = ft_pushfront(new, list);
	else
	{
		list = ft_sortsizerev2(new, list);
		if (list->prev == NULL)
		{
			list->prev = new;
			new->next = list;
			list = new;
			return (list);
		}
		list = ft_insertlist(list, new);
	}
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}
