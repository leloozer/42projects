/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:04:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_winner(t_env *env)
{
	ft_putstr("le joueur ");
	ft_putnbr(env->players[env->last_live - 1].number);
	ft_putstr(" (");
	ft_putstr(env->players[env->last_live - 1].name);
	ft_putendl(") a gagne !");
}

void	cycle_rate(t_env *env, int *input, int count)
{
	if (count == env->dump)
	{
		endwin();
		hexdump(env->mem, 4096);
		*input = 27;
	}
	if (*input == 32)
	{
		if (env->run)
			(env->run = 0);
		else
			(env->run = 1);
	}
	if (env->ncurses)
		usleep(env->rate);
	if (*input == 113 && env->rate < 500000)
		env->rate *= 2;
	if (*input == 119 && env->rate > 1250)
		env->rate /= 2;
}

void	run_processes2(t_env *env)
{
	t_process		*tmp;
	unsigned char	op;

	tmp = env->p_list;
	while (tmp)
	{
		if (!tmp->cycles)
		{
			op = env->mem[tmp->pc];
			if (valid_op(op))
				tmp->cycles = g_op_tab[op - 1].cycles_nb;
			else
				tmp->pc++;
		}
		if (tmp->cycles == 1)
			exec_op(env, tmp);
		if (tmp->cycles)
			tmp->cycles--;
		tmp = tmp->next;
	}
}

size_t	exec(t_env *env, size_t i)
{
	if (env->die <= i)
	{
		decr_die(env);
		remove_dead(env);
		return (count_living(env));
	}
	return (1);
}

void	run_processes(t_env *env)
{
	size_t	i;
	int		cycle_nbr;
	int		input;

	i = 0;
	cycle_nbr = 0;
	input = ERR;
	if (env->ncurses)
		init_ncurses(env);
	while (exec(env, i) && input != 27)
	{
		input = getch();
		if (env->run)
		{
			if (i >= env->die)
				i = 0;
			run_processes2(env);
			i++;
			cycle_nbr++;
		}
		if (env->ncurses)
			print_mem(env, cycle_nbr);
		cycle_rate(env, &input, cycle_nbr);
	}
	endwin();
}
