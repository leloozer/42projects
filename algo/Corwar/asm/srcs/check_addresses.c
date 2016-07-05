/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_addresses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:11:18 by ndauteui          #+#    #+#             */
/*   Updated: 2016/04/01 19:12:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_check_prev_exists(t_tlist *tlist, char *s)
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
			return (1);
		if (tmp->type != ENDL)
			dist_prev += tmp->weight;
		tmp = tmp->prev;
	}
	return (0);
}

int			ft_check_next_exists(t_tlist *tlist, char *s)
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
			return (1);
		dist_next += tmp->weight;
		tmp = tmp->next;
	}
	return (0);
}
