/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:11:21 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 17:25:17 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_endrecursive(t_param *env, t_anthill *anthill, t_room *start,
		t_tube *tmp)
{
	ft_inanthillend(anthill, start);
	env->tub = tmp;
}

void	ft_initialanthill(t_anthill *anthill)
{
	anthill->start = NULL;
	anthill->end = NULL;
}

int		main(void)
{
	t_param		*env;
	t_anthill	*anthill;
	t_queue		*queue;

	if ((env = (t_param *)malloc(sizeof(t_param))) == NULL)
		return (-1);
	if ((anthill = (t_anthill *)malloc(sizeof(t_anthill))) == NULL)
		return (-1);
	if ((queue = (t_queue *)malloc(sizeof(t_queue))) == NULL)
		return (-1);
	ft_initialenv(env);
	ft_initialanthill(anthill);
	ft_initqueue(queue);
	if (ft_parse(env, anthill) == 1)
		ft_connect(env, anthill, queue);
	ft_freeanthill(anthill);
	ft_freequeue(queue);
	ft_freeenv(env);
	return (0);
}
