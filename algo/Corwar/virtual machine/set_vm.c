/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:04:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		count_players(t_env *env)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (i < MAX_PLAYERS)
	{
		if (env->players[i++].name)
			num++;
	}
	return (num);
}

void	set_in_mem(t_env *env, t_champ player)
{
	size_t	i;

	i = 0;
	while (i < player.size)
	{
		env->mem[player.pc + i] = player.data[i];
		env->color[player.pc + i] = player.number;
		i++;
	}
}

void	set_vm(t_env *env)
{
	int		i;
	int		check;
	int		offset;

	i = 0;
	check = 0;
	offset = MEM_SIZE / count_players(env);
	while (i < MAX_PLAYERS)
	{
		if (env->players[i].name)
		{
			env->players[i].pc = offset * check;
			set_in_mem(env, env->players[i]);
			check++;
		}
		i++;
	}
}
