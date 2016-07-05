/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:04:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	decr_die(t_env *env)
{
	if (env->live >= NBR_LIVE || env->max_cycles >= MAX_CHECKS)
	{
		if (env->die < CYCLE_DELTA)
			env->die = 0;
		else
			env->die -= CYCLE_DELTA;
		env->max_cycles = 0;
	}
	else
		env->max_cycles++;
}

void	remove_dead(t_env *env)
{
	t_process	*tmp;
	t_process	*tmp2;

	tmp = env->p_list;
	while (tmp)
	{
		if (!tmp->live)
		{
			tmp2 = tmp->next;
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				env->p_list = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp);
			tmp = tmp2;
		}
		else
		{
			tmp->live = 0;
			tmp = tmp->next;
		}
	}
}

size_t	count_living(t_env *env)
{
	t_process	*tmp;
	size_t		count;

	count = 0;
	tmp = env->p_list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
