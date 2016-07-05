/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:56:47 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 17:01:47 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkusepipe(t_param *env, t_room *start, t_queue *queue)
{
	t_tube	*tmp;
	t_queue	*tmpqueue;

	tmp = env->tub;
	tmpqueue = queue;
	while (tmp)
	{
		if ((tmp->use == 0) &&
			((ft_strcmp(tmp->t_1, start->name) == 0) ||
			(ft_strcmp(tmp->t_2, start->name)) == 0))
			return (1);
		tmp = tmp->next;
	}
	while (tmpqueue->ok == 1 && tmpqueue->next)
		tmpqueue = tmpqueue->next;
	if (queue->next == NULL)
		ft_errorandexit(6);
	else
		return (1);
	return (0);
}

void	ft_firsttabenv(char **room, t_param *env)
{
	t_room	*new;
	int		i;

	i = 0;
	if ((new = (t_room *)malloc(sizeof(t_room))) != NULL)
	{
		new->name = room[0];
		new->x = ft_atoi(room[1]);
		new->y = ft_atoi(room[2]);
		new->flag = 0;
		new->fils = 0;
		while (i <= 1000)
		{
			new->prev[i] = NULL;
			new->next[i] = NULL;
			i++;
		}
		env->tab = new;
	}
}

void	ft_pushbacktabenv(char **room, t_param *env)
{
	t_room	*new;
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = env->tab;
	if ((new = (t_room *)malloc(sizeof(t_room))) != NULL)
	{
		while (env->tab->next[0] != NULL)
			env->tab = env->tab->next[0];
		new->name = room[0];
		new->x = ft_atoi(room[1]);
		new->y = ft_atoi(room[2]);
		new->flag = 0;
		new->fils = 0;
		new->next[0] = NULL;
		new->prev[0] = env->tab;
		while (++i <= 300)
		{
			new->next[i] = NULL;
			new->prev[i] = NULL;
		}
		env->tab->next[0] = new;
	}
	env->tab = tmp;
}

void	ft_firsttubenv(char **pipe, t_param *env)
{
	t_tube	*new;

	if ((new = (t_tube *)malloc(sizeof(t_tube))) != NULL)
	{
		new->t_1 = pipe[0];
		new->t_2 = pipe[1];
		new->nbr = 0;
		new->use = 0;
		new->next = NULL;
		new->prev = NULL;
		env->tub = new;
	}
}

void	ft_pushbacktubenv(char **pipe, t_param *env)
{
	t_tube	*new;
	t_tube	*tmp;
	int		i;

	i = 1;
	tmp = env->tub;
	if ((new = (t_tube *)malloc(sizeof(t_tube))) != NULL)
	{
		while (env->tub->next != NULL)
		{
			env->tub = env->tub->next;
			i++;
		}
		new->t_1 = pipe[0];
		new->t_2 = pipe[1];
		new->nbr = i;
		new->use = 0;
		new->next = NULL;
		new->prev = env->tub;
		env->tub->next = new;
	}
	env->tub = tmp;
}
