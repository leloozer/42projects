/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:57:46 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 11:29:39 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_sorttime2(t_file *new, t_file *list)
{
	while (list->next && new->fortime < list->fortime)
		list = list->next;
	if (list && new->fortime == list->fortime)
	{
		while (list->next && new->fortime == list->fortime &&
				new->nsec < list->nsec)
			list = list->next;
		if (list->next && (new->fortime == list->fortime) &&
				(new->nsec == list->nsec))
		{
			while (list->next && (ft_strcmp(new->name, list->name) > 0) &&
					(new->fortime == list->fortime) &&
					(new->nsec == list->nsec))
				list = list->next;
		}
	}
	return (list);
}

t_file	*ft_sorttime2rev(t_file *new, t_file *list)
{
	while (list->next && new->fortime > list->fortime)
		list = list->next;
	if (list && new->fortime == list->fortime)
	{
		while (list->next && new->fortime == list->fortime &&
				new->nsec > list->nsec)
			list = list->next;
		if (list->next && (new->fortime == list->fortime) &&
				(new->nsec == list->nsec))
		{
			while (list->next && (ft_strcmp(new->name, list->name) < 0) &&
					(new->fortime == list->fortime) &&
					(new->nsec == list->nsec))
				list = list->next;
		}
	}
	return (list);
}

t_file	*ft_sorttime(t_file *new, t_file *list)
{
	if (list == NULL)
	{
		list = new;
		return (list);
	}
	if (new->fortime > list->fortime)
		list = ft_pushfront(new, list);
	else
	{
		list = ft_sorttime2(new, list);
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

t_file	*ft_sorttimerev(t_file *new, t_file *list)
{
	if (list == NULL)
	{
		list = new;
		return (list);
	}
	if (new->fortime < list->fortime)
		list = ft_pushfront(new, list);
	else
	{
		list = ft_sorttime2rev(new, list);
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
