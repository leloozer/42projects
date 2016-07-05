/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*count_processes(t_process *p)
{
	t_process	*tmp;
	int			i;

	i = 0;
	tmp = p;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (ft_itoa(i));
}

void	print_hud(t_env *env, int count)
{
	int		i;

	draw_borders(env->my_hud);
	if (env->run)
		mvwprintw(env->my_hud, 2, 3, "** RUNNING **");
	else
		mvwprintw(env->my_hud, 2, 3, "** PAUSED  **");
	mvwprintw(env->my_hud, 4, 3, "cycles:");
	mvwprintw(env->my_hud, 4, 11, ft_itoa(count));
	mvwprintw(env->my_hud, 5, 3, "cycles/sec:");
	mvwprintw(env->my_hud, 5, 15, "     ");
	if (env->rate == 1250)
		mvwprintw(env->my_hud, 5, 15, "MAX");
	else
		mvwprintw(env->my_hud, 5, 15, ft_itoa(1000000 / env->rate));
	mvwprintw(env->my_hud, 7, 3, "processes:");
	mvwprintw(env->my_hud, 7, 14, count_processes(env->p_list));
	i = print_champs(env);
	print_infos(env, i);
}

void	move_coord(int *x, int *y, int *i, t_env *env)
{
	*x += 2;
	*i += 1;
	if (*i % 64 == 0)
	{
		*y += 1;
		*x = 3;
	}
	else
	{
		mvwprintw(env->my_screen, *y, *x, " ");
		*x += 1;
	}
}

void	print_mem(t_env *env, int count)
{
	char	tab[3];
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 2;
	x = 3;
	draw_borders(env->my_screen);
	while (i < MEM_SIZE)
	{
		wattron(env->my_screen, COLOR_PAIR(env->color[i]));
		get_hexa(tab, env, i);
		mvwprintw(env->my_screen, y, x, tab);
		wattroff(env->my_screen, COLOR_PAIR(env->color[i]));
		if (env->color[i] < 8)
			pc_color(env, i, x, y);
		reset_color(env, i);
		move_coord(&x, &y, &i, env);
	}
	print_hud(env, count);
	refresh_ncurses(env);
}

void	init_ncurses(t_env *env)
{
	env->my_win = initscr();
	noecho();
	cbreak();
	curs_set(0);
	nodelay(env->my_win, TRUE);
	refresh();
	wrefresh(env->my_win);
	mvprintw(1, 2, "ESC");
	env->my_screen = newwin(SCREEN_HEIGHT,
		SCREEN_WIDTH, SCREEN_STARTY, SCREEN_STARTX);
	box(env->my_screen, 0, 0);
	env->my_hud = newwin(HUD_HEIGHT, HUD_WIDTH, HUD_STARTY, HUD_STARTX);
	box(env->my_hud, 0, 0);
	set_color();
}
