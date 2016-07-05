/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	refresh_ncurses(t_env *env)
{
	wrefresh(env->my_hud);
	wrefresh(env->my_screen);
	refresh();
}

void	draw_borders(WINDOW *screen)
{
	int		x;
	int		y;
	int		i;

	wattron(screen, COLOR_PAIR(13));
	getmaxyx(screen, y, x);
	i = 0;
	while (i < y)
	{
		mvwprintw(screen, i, x - 1, " ");
		mvwprintw(screen, i, 0, " ");
		i++;
	}
	i = 0;
	while (i < x)
	{
		mvwprintw(screen, y - 1, i, " ");
		mvwprintw(screen, 0, i, " ");
		i++;
	}
	wattroff(screen, COLOR_PAIR(13));
}

int		print_champs(t_env *env)
{
	t_champ		*tmp;
	int			i;
	int			j;

	i = 9;
	j = 0;
	tmp = env->players;
	while (j < MAX_PLAYERS)
	{
		if (tmp[j].name)
		{
			mvwprintw(env->my_hud, i, 3, "player");
			mvwprintw(env->my_hud, i, 9, ft_itoa(tmp[j].number));
			mvwprintw(env->my_hud, i, 10, ":");
			wattron(env->my_hud, COLOR_PAIR(j + 1));
			mvwprintw(env->my_hud, i++, 12, tmp[j].name);
			wattroff(env->my_hud, COLOR_PAIR(j + 1));
			mvwprintw(env->my_hud, i, 3, "live:");
			mvwprintw(env->my_hud, i++, 12, ft_itoa(tmp[j].live));
			i++;
		}
		j++;
	}
	return (i);
}

void	print_infos(t_env *env, int i)
{
	mvwprintw(env->my_hud, i, 3, "CYCLE TO DIE:");
	mvwprintw(env->my_hud, i, 17, ft_itoa(env->die));
	i += 2;
	mvwprintw(env->my_hud, i, 3, "CYCLE DELTA:");
	mvwprintw(env->my_hud, i, 17, ft_itoa(CYCLE_DELTA));
	i += 2;
	mvwprintw(env->my_hud, i, 3, "LAST LIVE:");
	mvwprintw(env->my_hud, i, 14, "             ");
	wattron(env->my_hud, COLOR_PAIR(env->last_live));
	mvwprintw(env->my_hud, i++, 14, env->players[env->last_live - 1].name);
	wattroff(env->my_hud, COLOR_PAIR(env->last_live));
}
