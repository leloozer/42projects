/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:49:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/24 11:37:29 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key(int k, t_env *env)
{
	t_data	*data;

	data = env->data;
	data->h = k == 69 ? data->h + 1 : data->h + 0;
	data->h = k == 78 ? data->h - 1 : data->h - 0;
	data->scale = k == 88 ? data->scale + 1 : data->scale + 0;
	if (k == 92)
		data->scale = data->scale - 1 > 0 ? data->scale - 1 : data->scale - 0;
	data->origine_y = k == 123 ? data->origine_y + 20 : data->origine_y + 0;
	data->origine_y = k == 124 ? data->origine_y - 20 : data->origine_y - 0;
	data->origine_y = k == 125 ? data->origine_y + 20 : data->origine_y + 0;
	data->origine_x = k == 125 ? data->origine_x + 20 : data->origine_x + 0;
	data->origine_y = k == 126 ? data->origine_y - 20 : data->origine_y - 0;
	data->origine_x = k == 126 ? data->origine_x - 20 : data->origine_x + 0;
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img.adr);
	ft_initimg(env);
	ft_iso(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.adr, 0, 0);
	if (k == 53)
		exit(0);
	return (0);
}
