/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addresses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:36:11 by ndauteui          #+#    #+#             */
/*   Updated: 2016/04/01 13:16:58 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_check_prev(t_tlist *tlist, char *s)
{
	int		dist_prev;
	t_tlist	*tmp;

	dist_prev = 0;
	tmp = tlist;
	while (tmp->prev && (tmp->type != INSTRUCTION &&
		tmp->type != INSTRUCTION_SPE))
		tmp = tmp->prev;
	if (tmp->type == ENDL || tmp->prev->type == ENDL)
		tmp = tmp->prev;
	if (tmp->type == LABEL && ft_strequ(tmp->content, s) == 1)
		return (1);
	while (tmp->prev)
	{
		if (tmp->type == LABEL && ft_strequ(tmp->content, s) == 1)
			return (dist_prev);
		if (tmp->type != ENDL)
			dist_prev += tmp->weight;
		tmp = tmp->prev;
	}
	return (0);
}

int			ft_check_next(t_tlist *tlist, char *s)
{
	int		dist_next;
	t_tlist	*tmp;

	dist_next = 0;
	tmp = tlist;
	while (tmp->prev && (tmp->type != INSTRUCTION &&
		tmp->type != INSTRUCTION_SPE))
		tmp = tmp->prev;
	while (tmp->next)
	{
		if (tmp->type == LABEL && ft_strequ(tmp->content, s) == 1)
			return (dist_next);
		dist_next += tmp->weight;
		tmp = tmp->next;
	}
	return (0);
}

int			ft_look_for_label(t_tlist *tmp)
{
	int		dist_prev;
	int		dist_next;

	dist_prev = ft_check_prev(tmp, tmp->content);
	dist_next = ft_check_next(tmp, tmp->content);
	if (ft_check_prev_exists(tmp, tmp->content) == 0 &&
		ft_check_next_exists(tmp, tmp->content) == 0)
		ft_error(ft_strjoin(ft_strjoin("Label for ", tmp->content),
		" not found."));
	else if (ft_check_prev_exists(tmp, tmp->content) == 1 &&
		ft_check_next_exists(tmp, tmp->content) == 1)
		ft_error(ft_strjoin(ft_strjoin("Duplicate symbol for ",
		tmp->content), "."));
	if (dist_prev != 0)
		return (-dist_prev);
	else if (dist_next != 0)
		return (dist_next);
	return (0);
}

t_tlist		*ft_set_addresses(t_tlist *tlist)
{
	t_tlist	*tmp;

	tmp = tlist;
	while (tmp)
	{
		if (tmp->type == PARAM_LABEL_DIR || tmp->type == PARAM_LABEL_IND)
			tmp->addr = ft_look_for_label(tmp);
		tmp = tmp->next;
	}
	return (tlist);
}
