/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_s_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:47:57 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 16:05:34 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		ft_anthillstartend(char *line, t_param *env, t_anthill *anthill)
{
	char **room;

	if (ft_strsearch(line, ' ') == 0)
		ft_errorandexit(1);
	room = ft_strsplit(line, ' ');
	if ((env->start == 1) && (ft_checkroomname(room) == 0))
	{
		ft_go_anthill_start(room, anthill);
		env->start++;
		return (0);
	}
	else if ((env->end == 1) && (ft_checkroomname(room) == 0))
	{
		ft_go_anthill_end(room, anthill);
		env->end++;
		return (0);
	}
	else if ((env->start > 2 || env->end > 2) || ft_checkroomname(room) == 1)
		ft_errorandexit(10);
	return (0);
}

void	ft_go_anthill_start(char **room, t_anthill *anthill)
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
		anthill->start = new;
	}
}

void	ft_go_anthill_end(char **room, t_anthill *anthill)
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
		anthill->end = new;
	}
}
