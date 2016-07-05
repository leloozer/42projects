/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:12:00 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 17:27:38 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_read_line(char *line, t_param *env, t_anthill *anthill)
{
	int	retcom;
	int	retroom;

	retroom = 10;
	retcom = ft_checkcom(line, env);
	if (retcom == 1)
		return (0);
	if ((env->antsnbr > 0 && retcom == 0 && env->tub == NULL) &&
			(env->start != 1 && env->end != 1))
		retroom = ft_checkroom(line, env);
	else if (env->antsnbr == 0 && ft_checkants(line, env) == 1)
		return (0);
	else if ((env->start == 1) && (env->end == 1))
		ft_errorandexit(10);
	else if ((env->start == 1) || (env->end == 1))
	{
		ft_anthillstartend(line, env, anthill);
		return (0);
	}
	ft_read_line_suite(line, env, anthill, retroom);
	return (0);
}

int		ft_read_line_suite(char *line, t_param *env, t_anthill *anthill,
		int retroom)
{
	int retcom;

	retcom = ft_checkcom(line, env);
	if ((retcom == 0) && (env->tub != NULL))
	{
		if ((ft_checktube(line, env, anthill) == 0) || (retroom == 1))
			ft_errorandexit(10);
		return (0);
	}
	if ((retcom == 0) && (env->tub == NULL))
	{
		if ((retroom == 0) && (env->start != 2 || env->end != 2))
			ft_errorandexit(10);
		else if (retroom == 2)
			ft_checktube(line, env, anthill);
		return (0);
	}
	return (0);
}

void	ft_initialenv(t_param *env)
{
	env->antsnbr = 0;
	env->start = 0;
	env->end = 0;
	env->tab = NULL;
	env->tub = NULL;
}

int		ft_parse(t_param *env, t_anthill *anthill)
{
	char	*line;
	int		flag;

	flag = 0;
	while ((get_next_line(0, &line)) == 1)
	{
		flag++;
		ft_read_line(line, env, anthill);
		free(line);
	}
	if (flag == 0)
		ft_errorandexit(10);
	return (1);
}
