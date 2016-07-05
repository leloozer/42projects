/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 21:14:36 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/24 11:40:04 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawpixel(t_env *env, int x, int y, t_map *map)
{
	int	pos;

	if ((x < env->map_x && y < env->map_y && x >= 0 && y >= 0))
	{
		pos = (x * env->img.bpp / 8) + (y * env->img.sl);
		env->img.img[pos] = 255 - ((map->z + 10) * 3);
		env->img.img[pos + 1] = 255 - ((map->z + 5) * 4);
		env->img.img[pos + 2] = 255;
	}
}

void	ft_drawline(t_env *env, t_data *data, t_map *map)
{
	data->dh = env->x_b - env->x_a;
	data->dl = env->y_b - env->y_a;
	data->c = -1;
	data->m = ft_abs(data->dh) > ft_abs(data->dl) ?
		ft_abs(data->dh) : ft_abs(data->dl);
	while (++data->c < data->m)
		ft_drawpixel(env, env->x_a + (data->c * data->dh) / data->m,
				env->y_a + (data->c * data->dl) / data->m, map);
}
