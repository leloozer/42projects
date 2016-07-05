/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:12:25 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/25 13:34:28 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkants(char *line, t_param *env)
{
	if (ft_isnum(line) == 0)
	{
		if ((ft_atoll(line)) < 0 || (ft_atoll(line)) > 2147483647)
			ft_errorandexit(0);
		else
		{
			env->antsnbr = ft_atoi(line);
			return (1);
		}
	}
	ft_errorandexit(0);
	return (0);
}

int		ft_checkroom(char *line, t_param *env)
{
	char **room_name;

	if ((ft_strsearch(line, '-') == 1) && (env->start == 2) && (env->end == 2))
		return (2);
	if (ft_strsearch(line, ' ') == 0)
		ft_errorandexit(1);
	room_name = ft_strsplit(line, ' ');
	if (ft_checkroomname(room_name) == 0)
	{
		if (env->tab == NULL)
			ft_firsttabenv(room_name, env);
		else
			ft_pushbacktabenv(room_name, env);
		return (1);
	}
	return (0);
}

int		ft_checkcom(char *line, t_param *env)
{
	if ((line[0] == '#') && (ft_strcmp(line, "##start") != 0) &&
			(ft_strcmp(line, "##end") != 0))
		return (1);
	else if (ft_strcmp(line, "##start") == 0 && env->antsnbr > 0)
	{
		env->start++;
		return (1);
	}
	else if (ft_strcmp(line, "##end") == 0 && env->antsnbr > 0)
	{
		env->end++;
		return (1);
	}
	return (0);
}

int		ft_checktube(char *line, t_param *env, t_anthill *anthill)
{
	char **pipe;

	if (ft_strsearch(line, '-') == 0)
		ft_errorandexit(2);
	pipe = ft_strsplit(line, '-');
	if (ft_checkpipename(pipe, env, anthill) == 0)
	{
		if (env->tub == NULL)
			ft_firsttubenv(pipe, env);
		else
			ft_pushbacktubenv(pipe, env);
		return (1);
	}
	return (0);
}

void	ft_inanthillend(t_anthill *anthill, t_room *start)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = anthill->end;
	tmp2 = malloc(sizeof(t_room));
	anthill->end->prev[0] = start;
	while (anthill->end->prev[0] != NULL)
	{
		tmp2 = anthill->end;
		anthill->end = anthill->end->prev[0];
		anthill->end->next[0] = tmp2;
	}
	anthill->end = tmp;
}
