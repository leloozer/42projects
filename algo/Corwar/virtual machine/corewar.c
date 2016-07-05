/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/10 16:28:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_error2(char *msg1, char *msg2)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(msg1, 2);
	ft_putendl_fd(msg2, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(0);
}

void	ft_error(char *msg)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(0);
}

int		print_start(t_env *env)
{
	t_champ		*tmp;
	int			i;

	i = 0;
	tmp = env->players;
	while (i < MAX_PLAYERS)
	{
		if (tmp[i].name)
		{
			ft_putstr("player");
			ft_putnbr(tmp[i].number);
			ft_putstr(": ");
			ft_putstr(tmp[i].name);
			ft_putstr(" \"");
			ft_putstr(tmp[i].comment);
			ft_putendl("\"");
		}
		i++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	check_errors(argc, argv);
	get_env(&env, argv, argc);
	print_start(&env);
	set_vm(&env);
	set_processes(&env);
	run_processes(&env);
	print_winner(&env);
	return (0);
}
