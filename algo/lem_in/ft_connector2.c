/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connector2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:21:06 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 16:34:43 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_connect(t_param *env, t_anthill *anthill, t_queue *queue)
{
	t_room	*tmpstart;
	t_room	*tmpend;
	int		i;

	i = 1;
	tmpstart = anthill->start;
	tmpend = anthill->end;
	ft_connectrecursive(env, anthill->start, anthill, queue);
	anthill->start = tmpstart;
	ft_print(env, anthill);
	anthill->start = tmpstart;
	while (anthill->end->prev[0] != NULL)
		anthill->end = anthill->end->prev[0];
	ft_printf("\n\n\033[32mVoici le meilleur chemin :\033[0m\n");
	while (anthill->end)
	{
		ft_printf("Room: %d, Name: %s, x: %d, y: %d \n", i, anthill->end->name,
				anthill->end->x, anthill->end->y);
		i++;
		anthill->end = anthill->end->next[0];
	}
	ft_printf("\n\n\033[32mRESULT:\033[0m\n");
	anthill->end = tmpend;
	ft_goodroad(env, anthill);
}

void	ft_goodroad(t_param *env, t_anthill *anthill)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = anthill->end;
	while ((env->antsnbr > 0) || (ft_check_flag(anthill) != 0))
	{
		while (anthill->end)
		{
			if ((anthill->end->prev[0] == NULL) && (env->antsnbr != 0))
			{
				env->antsnbr--;
				i++;
				anthill->end->flag = i;
			}
			if (ft_goodroadsuite(env, anthill) == 0)
				anthill->end = anthill->end->prev[0];
			else
				return ;
		}
		ft_printf("\n");
		anthill->end = tmp;
	}
}

int		ft_goodroadsuite(t_param *env, t_anthill *anthill)
{
	if (anthill->end->flag > 0)
	{
		if (anthill->end->next[0] == NULL)
			anthill->end->flag = 0;
		if (anthill->end->next[0] != NULL)
		{
			ft_printf("L\033[35m%d\033[0m-\033[32m%s\033[0m ",
					anthill->end->flag, anthill->end->next[0]->name);
			anthill->end->next[0]->flag = anthill->end->flag;
			anthill->end->flag = 0;
		}
		if ((anthill->end->next[0] == NULL) &&
			(ft_check_flag(anthill) == 0) && (env->antsnbr == 0))
			return (1);
	}
	return (0);
}

int		ft_check_flag(t_anthill *anthill)
{
	t_room *tmp;

	tmp = anthill->end;
	while (anthill->end)
	{
		if (anthill->end->flag != 0)
		{
			anthill->end = tmp;
			return (1);
		}
		anthill->end = anthill->end->prev[0];
	}
	anthill->end = tmp;
	return (0);
}

t_room	*ft_anthillstartprev(t_room *start)
{
	int	i;

	i = 0;
	start = start->prev[0];
	while (start->next[i]->next[0] != NULL)
	{
		if ((start->next[i] == NULL && start->prev[0] != NULL))
		{
			i = 0;
			start->flag = 0;
			start = start->prev[0];
		}
		i++;
		if (start->next[i]->next[0] == NULL)
		{
			start = start->next[i];
			return (start);
		}
	}
	return (start);
}
