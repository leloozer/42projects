/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:44:07 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/24 11:40:20 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_abs(int x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}

t_map		*ft_initmap(void)
{
	t_map	*new;

	if ((new = (t_map *)malloc(sizeof(*new))) == NULL)
		ft_error(-1);
	new->next = NULL;
	return (new);
}

void		ft_initimg(t_env *env)
{
	if ((env->img.adr =
				mlx_new_image(env->mlx, env->map_x, env->map_y)) == NULL)
		ft_error(-1);
	if ((env->img.img = mlx_get_data_addr(env->img.adr, &env->img.bpp,
					&env->img.sl, &env->img.endian)) == NULL)
		ft_error(-1);
}

static void	ft_adapt(t_data *data, t_env *env)
{
	env->map_x = 1200;
	env->map_y = 1000;
	if (data->lenght_line > 50 &&
			data->lenght_line < 90)
	{
		data->scale = 5;
		data->h = 5;
	}
	else if (data->lenght_line >= 0 &&
			data->lenght_line <= 50)
	{
		data->scale = 30;
		data->h = 10;
	}
	else
	{
		data->scale = 2;
		data->h = 1;
	}
	data->origine_x = 300;
	data->origine_y = -250;
}

int			main(int argc, char **argv)
{
	t_env	env;
	t_data	data;

	if (argc != 2)
		ft_error(-1);
	ft_parse(argv[1], &data);
	ft_adapt(&data, &env);
	if ((env.mlx = mlx_init()) == NULL)
		ft_error(-1);
	if ((env.win = mlx_new_window(env.mlx, env.map_x, env.map_y,
					"fdf")) == NULL)
		ft_error(-1);
	ft_initimg(&env);
	mlx_hook(env.win, 2, 1, ft_key, &env);
	env.data = &data;
	ft_iso(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.adr, 0, 0);
	mlx_loop(env.mlx);
}
