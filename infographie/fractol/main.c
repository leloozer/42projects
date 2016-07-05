/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:07:48 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/10 14:47:33 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_error(int argc, char **argv, t_env *env)
{
	if (argc != 2)
	{
		ft_printf("\033[0;31m use ./fractol and [-m] or [-j] or [-d] or [-b] ");
		ft_printf("or [-t]\033[0m\n");
		exit(0);
	}
	else if ((ft_strcmp(argv[1], "-m") != 0) && (ft_strcmp(argv[1], "-j") != 0)
			&& (ft_strcmp(argv[1], "-d") != 0)
			&& (ft_strcmp(argv[1], "-b") != 0)
			&& (ft_strcmp(argv[1], "-t") != 0))
	{
		ft_printf("\033[0;31m use ./fractol and [-m] or [-j] or [-d] or [-b] ");
		ft_printf("or [-t]\033[0m\n");
		exit(0);
	}
	else
		env->choise = argv[1];
	return (0);
}

void	ft_initval(t_env *env)
{
	env->image_x = 0;
	env->image_y = 0;
	env->mousex = 0.285;
	env->mousey = 0.01;
	env->mandelbrot = 0;
	env->julia = 0;
	env->burnship = 0;
	env->droit = 0;
	env->tricorne = 0;
	env->x1 = 0;
	env->x2 = 0;
	env->y1 = 0;
	env->y2 = 0;
	env->c_r = 0;
	env->c_i = 0;
	env->z_r = 0;
	env->z_i = 0;
	env->iteration = 0;
	env->i = 0;
	env->tmp = 0;
}

void	ft_init(t_env *env)
{
	env->win_l = 600;
	env->win_h = 600;
	env->zoom = 200;
	env->imax = 50;
	ft_initval(env);
	if (ft_strcmp(env->choise, "-m") == 0)
		env->mandelbrot = 1;
	if (ft_strcmp(env->choise, "-j") == 0)
		env->julia = 1;
	if (ft_strcmp(env->choise, "-d") == 0)
		env->droit = 1;
	if (ft_strcmp(env->choise, "-b") == 0)
		env->burnship = 1;
	if (ft_strcmp(env->choise, "-t") == 0)
		env->tricorne = 1;
	ft_initfract(env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_h, env->win_l, "Fractol");
}

void	ft_initimg(t_env *env)
{
	if (!(env->adr = mlx_new_image(env->mlx, env->win_h, env->win_l)))
		exit(1);
	if (!(env->img = mlx_get_data_addr(env->adr, &env->bpp, &env->sl,
					&env->endian)))
		exit(1);
}

int		main(int argc, char **argv)
{
	t_env	env;

	ft_error(argc, argv, &env);
	ft_init(&env);
	ft_initimg(&env);
	ft_fractal(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.adr, 0, 0);
	mlx_hook(env.win, 2, (1L << 0), ft_key, &env);
	mlx_hook(env.win, 6, (1L >> 0), ft_modifjulia, &env);
	mlx_mouse_hook(env.win, ft_mouseforzoom, &env);
	mlx_loop(env.mlx);
	return (0);
}
