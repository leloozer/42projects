/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:26:50 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/24 16:32:09 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_insertlist(t_file *list, t_file *new)
{
	list = list->prev;
	if (list && list->next != NULL)
		list->next->prev = new;
	new->next = list->next;
	new->prev = list;
	list->next = new;
	return (list);
}

t_file	*ft_pushfront(t_file *new, t_file *list)
{
	list->prev = new;
	new->next = list;
	list = new;
	return (list);
}

t_file	*ft_sortfile(t_option *opt, t_file *new, t_file *list)
{
	if (opt->t == 0 && opt->r == 0 && opt->maj_s == 0)
		list = ft_sortname(new, list);
	if (opt->t == 0 && opt->r == 1 && opt->maj_s == 0)
		list = ft_sortnamerev(new, list);
	if (opt->maj_s == 1 && opt->r == 0)
		list = ft_sortsize(new, list);
	if (opt->maj_s == 1 && opt->r == 1)
		list = ft_sortsizerev(new, list);
	else if (opt->t == 1 && opt->r == 0)
		list = ft_sorttime(new, list);
	else if (opt->t == 1 && opt->r == 1)
		list = ft_sorttimerev(new, list);
	return (list);
}

t_file	*ft_sortnamerev(t_file *new, t_file *list)
{
	if (list->name == NULL)
		list = new;
	else
	{
		if (ft_strcmp(new->name, list->name) > 0)
		{
			list->prev = new;
			new->next = list;
			list = new;
		}
		else
		{
			while (list->next && (ft_strcmp(new->name, list->name) < 0) &&
					(ft_strcmp(new->name, list->next->name) < 0))
				list = list->next;
			if (list->next != NULL)
				list->next->prev = new;
			new->next = list->next;
			new->prev = list;
			list->next = new;
		}
	}
	while (list->prev)
		list = list->prev;
	return (list);
}

t_file	*ft_sortname(t_file *new, t_file *list)
{
	if (list->name == NULL)
		list = new;
	else
	{
		if (ft_strcmp(new->name, list->name) < 0)
		{
			list->prev = new;
			new->next = list;
			list = new;
		}
		else
		{
			while (list->next && (ft_strcmp(new->name, list->name) > 0) &&
					(ft_strcmp(new->name, list->next->name) > 0))
				list = list->next;
			if (list->next != NULL)
				list->next->prev = new;
			new->next = list->next;
			new->prev = list;
			list->next = new;
		}
	}
	while (list->prev)
		list = list->prev;
	return (list);
}
