/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:20:16 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 15:47:06 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_freeanthill(t_anthill *anthill)
{
	t_room	*tmp;

	tmp = anthill->start;
	while (tmp->next[0])
	{
		anthill->start = tmp;
		tmp = tmp->next[0];
		free(anthill->start);
	}
}

void	ft_freequeue(t_queue *queue)
{
	t_queue	*tmp;

	tmp = queue;
	while (tmp->next)
	{
		queue = tmp;
		tmp = tmp->next;
		free(queue);
	}
}

void	ft_freeenv(t_param *env)
{
	t_tube	*tmp;

	tmp = env->tub;
	while (tmp->next)
	{
		env->tub = tmp;
		tmp = tmp->next;
		free(env->tub);
	}
}
