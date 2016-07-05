/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:41:18 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/30 15:48:56 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initfract2(t_env *env)
{
	if (env->burnship == 1)
	{
		env->x1 = -2;
		env->x2 = 2;
		env->y1 = -1.7;
		env->y2 = 1.7;
	}
	if (env->tricorne == 1)
	{
		env->x1 = -1.7;
		env->x2 = 1.7;
		env->y1 = -1.3;
		env->y2 = 1.3;
	}
}

void	ft_initfract(t_env *env)
{
	if (env->mandelbrot == 1)
	{
		env->x1 = -2;
		env->x2 = 2;
		env->y1 = -1.3;
		env->y2 = 1.3;
	}
	if (env->julia == 1)
	{
		env->x1 = -1.4;
		env->x2 = 1.4;
		env->y1 = -1.5;
		env->y2 = 1.5;
		env->c_r = 0.285;
	}
	if (env->droit == 1)
	{
		env->x1 = -2.5;
		env->x2 = 2.5;
		env->y1 = -1.2;
		env->y2 = 1.2;
	}
	ft_initfract2(env);
}

void	ft_fractal(t_env *env)
{
	env->image_x = (env->x2 - env->x1) * env->zoom;
	env->image_y = (env->y2 - env->y1) * env->zoom;
	if (env->image_x > env->win_h * 4)
		env->image_x = env->win_h;
	if (env->image_y > env->win_l)
		env->image_y = env->win_l;
	if (env->mandelbrot == 1)
		ft_mandelbrot(env);
	if (env->julia == 1)
		ft_julia(env);
	if (env->droit == 1)
		ft_droit(env);
	if (env->burnship == 1)
		ft_burnship(env);
	if (env->tricorne == 1)
		ft_tricorne(env);
}

void	ft_mandelbrot(t_env *env)
{
	env->x = -1;
	while (++env->x < env->image_x)
	{
		env->y = -1;
		while (++env->y < env->image_y)
		{
			env->c_r = env->x / env->zoom + env->x1;
			env->c_i = env->y / env->zoom + env->y1;
			env->z_r = 0;
			env->z_i = 0;
			env->i = 0;
			while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 &&
					env->i < env->imax)
			{
				env->tmp = env->z_r;
				env->z_r = env->z_r * env->z_r - env->z_i * env->z_i
					+ env->c_r;
				env->z_i = 2 * env->z_i * env->tmp + env->c_i;
				env->i++;
				ft_drawpixel(env);
			}
		}
	}
}

void	ft_burnship(t_env *env)
{
	env->x = -1;
	while (++env->x < env->image_x)
	{
		env->y = -1;
		while (++env->y < env->image_y)
		{
			env->c_r = env->x / env->zoom + env->x1;
			env->c_i = env->y / env->zoom + env->y1;
			env->z_r = 0;
			env->z_i = 0;
			env->i = 0;
			while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 &&
					env->i < env->imax)
			{
				env->tmp = env->z_r;
				env->z_r = env->z_r * env->z_r - env->z_i * env->z_i
					+ env->c_r;
				env->z_i = fabs(2 * env->z_i * env->tmp) + env->c_i;
				env->i++;
				ft_drawpixel(env);
			}
		}
	}
}
