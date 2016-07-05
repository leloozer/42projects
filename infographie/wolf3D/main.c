/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:21:40 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/13 17:54:20 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

int		ft_error(int argc, char **argv, t_raytracer *raytracer)
{
	if (argc != 2)
	{
		ft_printf("\033[0;31m use ./wolf3d and -lvl[1-5]\n");
		exit(0);
	}
	else if ((ft_strcmp(argv[1], "-lvl1") != 0)
			&& (ft_strcmp(argv[1], "-lvl2") != 0)
			&& (ft_strcmp(argv[1], "-lvl3") != 0)
			&& (ft_strcmp(argv[1], "-lvl4") != 0)
			&& (ft_strcmp(argv[1], "-lvl5") != 0))
	{
		ft_printf("\033[0;31m use ./wolf3d and -lvl[1-5]\n");
		exit(0);
	}
	else
		raytracer->choise = ft_strdup(argv[1]);
	return (0);
}

char	**ft_intomap(t_raytracer *raytracer)
{
	char	*lvl;
	char	**map;

	if (ft_strcmp(raytracer->choise, "-lvl1") == 0)
		lvl = ft_lvl1(raytracer);
	else if (ft_strcmp(raytracer->choise, "-lvl2") == 0)
		lvl = ft_lvl2(raytracer);
	else if (ft_strcmp(raytracer->choise, "-lvl3") == 0)
		lvl = ft_lvl3(raytracer);
	else if (ft_strcmp(raytracer->choise, "-lvl4") == 0)
		lvl = ft_lvl4(raytracer);
	else
		lvl = ft_lvl5(raytracer);
	map = ft_strsplit(lvl, ',');
	return (map);
}

void	ft_mapinit(t_raytracer *raytracer)
{
	int		x;
	int		y;
	char	**map;
	int		i;

	x = 0;
	i = 0;
	map = ft_intomap(raytracer);
	raytracer->map = (int **)malloc(sizeof(int *) * raytracer->size);
	while (x < raytracer->size)
	{
		y = 0;
		raytracer->map[x] = (int *)malloc(sizeof(int) * raytracer->size);
		while (y < raytracer->size)
		{
			raytracer->map[x][y] = ft_atoi(map[i]);
			i++;
			y++;
		}
		x++;
	}
}

void	ft_initraytracer(t_raytracer *raytracer)
{
	raytracer->plane_x = 0;
	raytracer->plane_y = 0.66;
	raytracer->player.dir_x = -1;
	raytracer->player.dir_y = 0;
	raytracer->player.pos_x = 3;
	raytracer->player.pos_y = 2;
	raytracer->env.win_h = 600;
	raytracer->env.win_l = 800;
	raytracer->jump = 0;
	ft_mapinit(raytracer);
}

int		main(int argc, char **argv)
{
	t_raytracer raytracer;

	ft_error(argc, argv, &raytracer);
	ft_initraytracer(&raytracer);
	raytracer.env.mlx = mlx_init();
	raytracer.env.win = mlx_new_window(raytracer.env.mlx,
			raytracer.env.win_l, raytracer.env.win_h, "Wolf3D");
	raytracer.env.adr = mlx_new_image(raytracer.env.mlx,
			raytracer.env.win_l, raytracer.env.win_h);
	raytracer.env.img = mlx_get_data_addr(raytracer.env.adr,
			&raytracer.env.bpp, &raytracer.env.sl, &raytracer.env.endian);
	ft_boucle(&raytracer);
	mlx_put_image_to_window(raytracer.env.mlx, raytracer.env.win,
			raytracer.env.adr, 0, 0);
	mlx_string_put(raytracer.env.mlx, raytracer.env.win, 50, 5, 0xff0000,
			"Jetpack: J");
	mlx_hook(raytracer.env.win, 2, 3, ft_key, &raytracer);
	mlx_hook(raytracer.env.win, 6, (1L >> 0), ft_mouse, &raytracer);
	mlx_loop(raytracer.env.mlx);
	return (0);
}
