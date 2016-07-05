/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:34:31 by ndauteui          #+#    #+#             */
/*   Updated: 2016/04/01 19:23:17 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_tlist		*ft_create_telem(char *content, int type)
{
	t_tlist	*new_elem;

	new_elem = (t_tlist*)malloc(sizeof(t_tlist));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = ft_strdup(content);
	new_elem->type = type;
	new_elem->addr = 0;
	new_elem->weight = 0;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

int			ft_get_size(t_tlist *tlist)
{
	t_tlist	*tmp;
	int		size;

	tmp = tlist;
	size = 0;
	while (tmp->next && (tmp->type != INSTRUCTION &&
		tmp->type != INSTRUCTION_SPE))
		tmp = tmp->next;
	while (tmp->next)
	{
		size += tmp->weight;
		tmp = tmp->next;
	}
	return (size);
}

t_tlist		*lol_norm(t_tlist *elem, t_tlist *tmp)
{
	elem->prev = tmp;
	elem->next = tmp->next;
	return (elem);
}

t_tlist		*ft_remove_labels(t_tlist *tlist)
{
	t_tlist	*tmp;
	t_tlist	*tmp2;
	t_tlist	*elem;

	tmp = tlist;
	tmp2 = tmp;
	while (tmp)
	{
		if (tmp->type == NAME)
		{
			elem = ft_create_telem(ft_itoa(ft_get_size(tmp)), SIZE);
			lol_norm(elem, tmp);
			tmp->next->prev = elem;
			tmp->next = elem;
		}
		if (tmp->type == LABEL)
		{
			tmp2->next = tmp->next;
			tmp->next->prev = tmp2;
			free(tmp);
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tlist);
}

t_tlist		*ft_create_and_add_telem(t_tlist *list, char *content, int type)
{
	t_tlist		*new_elem;
	t_tlist		*tmp;
	t_tlist		*tmp2;

	new_elem = ft_create_telem(content, type);
	if (!list)
		return (new_elem);
	tmp = list;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new_elem;
			tmp->prev = tmp2;
			break ;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (list);
}
