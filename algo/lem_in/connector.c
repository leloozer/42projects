/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:43:15 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 17:06:55 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_inanthill(t_room *forcpy, t_room *start)
{
	int		i;
	t_room	*copy;

	i = 0;
	copy = NULL;
	copy = ft_initroom(copy);
	while (start->next[i] != NULL)
		i++;
	ft_memcpy(copy, forcpy, sizeof(t_room));
	copy->prev[0] = start;
	copy->next[0] = NULL;
	start->next[i] = copy;
	return (start);
}

t_room	*ft_anthillson(t_param *env, char *t_1, char *t_2, t_room *start)
{
	t_room	*tmp;

	tmp = env->tab;
	while (env->tab != NULL)
	{
		if (((ft_strcmp(t_1, start->name) == 0) &&
			(ft_strcmp(t_2, env->tab->name) == 0)) ||
			((ft_strcmp(t_1, env->tab->name) == 0) &&
			(ft_strcmp(t_2, start->name) == 0)))
		{
			start = ft_inanthill(env->tab, start);
			env->tab = tmp;
			return (start);
		}
		env->tab = env->tab->next[0];
	}
	env->tab = tmp;
	return (start);
}

t_room	*ft_connectrecursive(t_param *env, t_room *start, t_anthill *anthill,
		t_queue *queue)
{
	t_tube	*tmp;

	tmp = env->tub;
	while (env->tub)
	{
		if (env->tub->use == 0 && ((ft_strcmp(env->tub->t_1, start->name) == 0)
					|| (ft_strcmp(env->tub->t_2, start->name)) == 0))
		{
			env->tub->use++;
			if ((ft_strcmp(env->tub->t_1, anthill->end->name) == 0) ||
					(ft_strcmp(env->tub->t_2, anthill->end->name) == 0))
			{
				ft_endrecursive(env, anthill, start, tmp);
				return (start);
			}
			else
				start = ft_anthillson(env, env->tub->t_1, env->tub->t_2, start);
		}
		env->tub = env->tub->next;
	}
	env->tub = tmp;
	start = ft_anthillstartnext(start, queue);
	if (ft_checkusepipe(env, start, queue) == 1)
		ft_connectrecursive(env, start, anthill, queue);
	return (start);
}

t_room	*ft_anthillstartnext(t_room *start, t_queue *queue)
{
	int		i;
	t_queue *tmp;

	i = 0;
	while (queue->ok == 1 && queue->next != NULL)
		queue = queue->next;
	if (queue->ok == 1 && queue->next == NULL)
		ft_initqueue(queue);
	tmp = queue;
	if (start->next[i] != NULL)
	{
		while (start->next[i] != NULL)
		{
			if (queue->output == NULL)
			{
				ft_firstqueue(queue, start->next[i]);
				tmp = queue;
			}
			else
				ft_addinput(queue, start->next[i]);
			i++;
		}
	}
	queue->ok = 1;
	return (queue->output);
}

void	ft_print(t_param *env, t_anthill *anthill)
{
	ft_printf("\n\033[35mNumber Ants: %d\033[0m\n\n", env->antsnbr);
	ft_printf("Start Name : %s, x : %d, y : %d\n", anthill->start->name,
			anthill->start->x, anthill->start->y);
	ft_printf("End Name : %s, x : %d, y : %d\n\n", anthill->end->name,
			anthill->end->x, anthill->end->y);
	while (env->tab->next[0] != NULL)
	{
		ft_printf("\033[32mOther Room Name : %s, x : %d, y : %d\033[0m\n",
				env->tab->name,
				env->tab->x, env->tab->y);
		env->tab = env->tab->next[0];
	}
	ft_printf("\033[32mOther Room Name : %s, x : %d, y : %d\033[0m\n\n",
			env->tab->name, env->tab->x, env->tab->y);
	while (env->tub->next != NULL)
	{
		ft_printf("Pipe for room %s and  %s, use : %d, number: %d\n",
				env->tub->t_1, env->tub->t_2, env->tub->use, env->tub->nbr);
		env->tub = env->tub->next;
	}
	ft_printf("Pipe for romm %s and  %s, use : %d , number: %d\n\n",
				env->tub->t_1, env->tub->t_2, env->tub->use, env->tub->nbr);
	ft_printf("\033[31m********************************************\033[0m\n");
}
