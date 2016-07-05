/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:13:20 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 15:46:54 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_counttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	i--;
	return (i);
}

int		ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int		ft_checkroomname(char **room_name)
{
	if (ft_counttab(room_name) != 2)
		ft_errorandexit(1);
	if ((ft_isnum(room_name[1]) != 0) || (ft_isnum(room_name[2]) != 0))
		ft_errorandexit(1);
	if (room_name[0][0] == 'L')
		ft_errorandexit(1);
	return (0);
}

int		ft_checkpipename(char **pipe, t_param *env, t_anthill *anthill)
{
	t_room	*tmp;
	int		ok;

	tmp = env->tab;
	ok = 0;
	if ((ft_counttab(pipe) != 1) || (ft_strcmp(pipe[0], pipe[1]) == 0))
		ft_errorandexit(2);
	while (env->tab != NULL)
	{
		if (ft_strcmp(env->tab->name, pipe[0]) == 0)
			ok++;
		if (ft_strcmp(env->tab->name, pipe[1]) == 0)
			ok++;
		env->tab = env->tab->next[0];
	}
	env->tab = tmp;
	if ((ft_strcmp(anthill->start->name, pipe[0]) == 0) ||
	(ft_strcmp(anthill->start->name, pipe[1]) == 0))
		ok++;
	if ((ft_strcmp(anthill->end->name, pipe[0]) == 0) ||
	(ft_strcmp(anthill->end->name, pipe[1]) == 0))
		ok++;
	if (ok != 2)
		ft_errorandexit(2);
	return (0);
}

void	ft_errorandexit(int x)
{
	if (x == 0)
		ft_printf("\033[31mWrong Ants Number\033[0m\n");
	else if (x == 1)
		ft_printf("\033[31mWrong Room\033[0m\n");
	else if (x == 2)
		ft_printf("\033[31mWrong Pipe\033[0m\n");
	else if (x == 6)
		ft_printf("\033[31mImpossible Map\033[0m\n");
	else if (x == 10)
		ft_printf("\033[31mError\033[0m\n");
	exit(0);
}
