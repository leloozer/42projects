/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_color(void)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, COLOR_BLUE);
	init_pair(11, COLOR_WHITE, COLOR_RED);
	init_pair(12, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(13, COLOR_WHITE, COLOR_WHITE);
}

void	reset_color(t_env *env, int i)
{
	if (env->color[i] > 8)
		env->color[i] -= 8;
	else if (env->color[i] > 4)
		env->color[i] -= 4;
}

void	pc_color(t_env *env, int i, int x, int y)
{
	char		tab[3];
	size_t		num;
	t_process	*tmp;
	int			color;

	tmp = env->p_list;
	while (tmp)
	{
		num = tmp->reg[0][3];
		if ((size_t)i == tmp->pc)
		{
			if (num > 0 && num <= 4)
				color = num + 4;
			else if (num == 0)
				color = env->color[i] + 4;
			wattron(env->my_screen, COLOR_PAIR(color));
			get_hexa(tab, env, i);
			mvwprintw(env->my_screen, y, x, tab);
			wattroff(env->my_screen, COLOR_PAIR(color));
		}
		tmp = tmp->next;
	}
}
