/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:04:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_reg(t_process *p, unsigned char num)
{
	int		i;
	int		j;

	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			p->reg[i][j] = 0;
			j++;
		}
		i++;
	}
	p->reg[0][REG_SIZE - 1] = num;
}

void	add_process(size_t pc, size_t num, t_env *env)
{
	t_process	*p;

	if (!(p = (t_process *)malloc(sizeof(t_process))))
		ft_error("Error : malloc failure");
	set_reg(p, num);
	p->pc = pc;
	p->carry = 0;
	p->cycles = 0;
	p->live = 0;
	p->start_pc = pc;
	p->next = NULL;
	p->prev = NULL;
	if (env->p_list)
	{
		env->p_list->prev = p;
		p->next = env->p_list;
	}
	env->p_list = p;
}

void	set_processes(t_env *env)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (env->players[i].name)
		{
			add_process(env->players[i].pc, env->players[i].number, env);
			env->last_live = env->players[i].number;
		}
		i++;
	}
}
