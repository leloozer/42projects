/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 21:14:36 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/10 16:37:50 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_drawpixel(t_env *env)
{
	int pos;

	if (env->x < env->win_h && env->y < env->win_l && env->x > 0 && env->y > 0)
	{
		if (env->i == env->imax)
		{
			pos = (env->x * env->bpp / 8) + (env->y * env->sl);
			env->img[pos] = 255;
			env->img[pos + 1] = 0;
			env->img[pos + 2] = 0;
		}
		else
		{
			pos = (env->x * env->bpp / 8) + (env->y * env->sl);
			env->img[pos] = 255 * env->i / env->imax;
			env->img[pos + 1] = 0;
			env->img[pos + 2] = 0;
		}
	}
}

int		ft_move(t_env *env)
{
	env->adr = mlx_new_image(env->mlx, env->win_h, env->win_l);
	env->img = mlx_get_data_addr(env->adr, &env->bpp, &env->sl, &env->endian);
	ft_fractal(env);
	mlx_put_image_to_window(env->mlx, env->win, env->adr, 0, 0);
	mlx_string_put(env->mlx, env->win, 50, 5, 0xff0000,
			"zoom:");
	mlx_string_put(env->mlx, env->win, 50, 30, 0xff0000,
	ft_itoa(env->zoom));
	mlx_string_put(env->mlx, env->win, 390, 30, 0xff0000,
			ft_itoa(env->imax));
	mlx_string_put(env->mlx, env->win, 390, 5, 0xff0000,
			"iteration:");
	return (0);
}
