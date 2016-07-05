/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 21:47:27 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/24 11:37:25 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init(t_map *map, t_env *env, t_data *data)
{
	env->x_a = data->origine_x + (map->x * data->scale) - map->z * data->h;
	env->y_a = data->origine_y + (map->y * data->scale) - map->z * data->h;
	env->x_a = env->x_a - env->y_a;
	env->y_a = (env->x_a + env->y_a) / 2 + (map->y * data->scale);
}

static void	ft_convertb(t_map *map, t_env *env, t_data *data)
{
	env->x_b = data->origine_x + (map->next->x * data->scale) -
		map->next->z * data->h;
	env->y_b = data->origine_y + (map->next->y * data->scale) -
		map->next->z * data->h;
	env->x_b = env->x_b - env->y_b;
	env->y_b = (env->x_b + env->y_b) / 2 + (map->y * data->scale);
}

static void	ft_converta(t_map *under, t_env *env, t_data *data)
{
	env->x_b = data->origine_x + (under->x * data->scale) -
		under->z * data->h;
	env->y_b = data->origine_y + (under->y * data->scale) -
		under->z * data->h;
	env->x_b = env->x_b - env->y_b;
	env->y_b = (env->x_b + env->y_b) / 2 + (under->y * data->scale);
}

void		ft_convertiso(t_map *under, t_map *map, t_env *env, t_data *data)
{
	while (map->next != NULL)
	{
		ft_init(map, env, data);
		if (map->y == map->next->y)
		{
			ft_convertb(map, env, data);
			ft_drawline(env, data, map);
		}
		if (under->next != NULL)
		{
			ft_converta(under, env, data);
			ft_drawline(env, data, map);
			under = under->next;
		}
		map = map->next;
	}
}

void		ft_iso(t_env *env)
{
	int		i;
	t_map	*under;
	t_map	*map;
	t_data	*data;

	data = env->data;
	map = data->first;
	under = map;
	i = data->lenght_line + 1;
	while (--i > 0)
		under = under->next;
	ft_convertiso(under, map, env, data);
}
