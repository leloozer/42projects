/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/10 16:28:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_players(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->players[i].number = i;
		env->players[i].name = NULL;
		env->players[i].comment = NULL;
		env->players[i].data = NULL;
		env->players[i].pc = 0;
		env->players[i].size = 0;
		i++;
	}
}

void	init_env(t_env *env)
{
	int	i;

	i = 0;
	env->max_cycles = 0;
	env->die = CYCLE_TO_DIE;
	env->live = 0;
	env->last_live = 0;
	env->my_win = NULL;
	env->my_screen = NULL;
	env->my_hud = NULL;
	env->rate = 10000;
	env->run = 0;
	env->dump = -1;
	env->p_list = NULL;
	env->ncurses = 0;
	while (i < MEM_SIZE)
		env->color[i++] = 0;
	i = 0;
	while (i < MEM_SIZE)
		env->mem[i++] = 0;
	init_players(env);
}
