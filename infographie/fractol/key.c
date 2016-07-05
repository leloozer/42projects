/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:04:03 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/31 15:08:38 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key(int key, t_env *env)
{
	env->imax = key == 69 ? env->imax + 1 : env->imax + 0;
	env->imax = key == 78 ? env->imax - 1 : env->imax + 0;
	env->y1 = key == 126 ? env->y1 + 0.1 : env->y1 + 0;
	env->y1 = key == 125 ? env->y1 - 0.1 : env->y1 + 0;
	env->x1 = key == 123 ? env->x1 + 0.1 : env->x1 + 0;
	env->x1 = key == 124 ? env->x1 - 0.1 : env->x1 + 0;
	env->zoom = key == 88 ? env->zoom + 50 : env->zoom + 0;
	env->zoom = key == 92 ? env->zoom - 80 : env->zoom + 0;
	if (key == 53)
	{
		mlx_destroy_image(env->mlx, env->adr);
		exit(1);
	}
	ft_move(env);
	return (0);
}

void	ft_dezoom(t_env *env)
{
	env->zoom -= 80;
}

void	ft_zoom(int x, int y, t_env *env)
{
	env->zoom += 50;
	if (x >= 0 && x <= 200 && y >= 200 && y <= 300)
		env->x1 -= 0.1;
	if (x <= 600 && x >= 400 && y >= 200 && y <= 300)
		env->x1 += 0.1;
	if (x <= 200 && y < 200)
	{
		env->x1 -= 0.1;
		env->y1 -= 0.1;
	}
	else if (x > 200 && y < 200)
	{
		env->x1 += 0.1;
		env->y1 -= 0.1;
	}
	else if (x > 200 && y > 300)
	{
		env->x1 += 0.1;
		env->y1 += 0.1;
	}
	else if (x <= 200 && y > 300)
	{
		env->x1 -= 0.1;
		env->y1 += 0.1;
	}
}

int		ft_mouseforzoom(int bouton, int x, int y, t_env *env)
{
	if (x >= 0 && x <= env->win_h && y >= 0 &&
			y <= env->win_l && bouton == 6)
		ft_zoom(x, y, env);
	if (x >= 0 && x <= env->win_h && y >= 0 &&
			y <= env->win_l && bouton == 7)
		ft_dezoom(env);
	ft_move(env);
	return (0);
}

int		ft_modifjulia(int x, int y, t_env *env)
{
	if (x >= 0 && x <= env->win_h && y >= 0 &&
			y <= env->win_l)
	{
		if (x >= 0 && x <= 100)
			env->mousex = (float)x / 100;
		if (x > 100 && x <= 200)
			env->mousex = (float)x / 180;
		if (x > 200 && x <= 300)
			env->mousex = (float)x / 250;
		if (x > 300 && x <= 400)
			env->mousex = (float)x / 300;
		if (x > 400 && x <= 500)
			env->mousex = (float)x / 350;
		if (x > 500 && x <= 600)
			env->mousex = (float)x / 400;
		env->mousey = 0.01;
	}
	ft_move(env);
	return (0);
}
