/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:44:49 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/30 15:47:16 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_tricorne(t_env *env)
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
				env->z_i = -2 * env->z_i * env->tmp + env->c_i;
				env->i++;
				ft_drawpixel(env);
			}
		}
	}
}

void		ft_julia(t_env *env)
{
	env->x = -1;
	while (++env->x < env->image_x)
	{
		env->y = -1;
		while (++env->y < env->image_y)
		{
			env->c_r = env->mousex;
			env->c_i = env->mousey;
			env->z_r = env->x / env->zoom + env->x1;
			env->z_i = env->y / env->zoom + env->y1;
			env->i = 0;
			while (env->z_r * env->z_r + env->z_i * env->z_i < 4 && env->i
					< env->imax)
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

void		ft_droit(t_env *env)
{
	env->x = -1;
	while (++env->x < env->image_x)
	{
		env->y = -1;
		while (++env->y < env->image_y)
		{
			env->c_r = 0.4;
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
