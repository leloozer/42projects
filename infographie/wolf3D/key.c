/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:22:56 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/13 16:51:54 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void	ft_moveright(t_raytracer *raytracer)
{
	double	oldirx;
	double	oldplanex;

	oldirx = 0;
	oldplanex = 0;
	oldirx = raytracer->player.dir_x;
	raytracer->player.dir_x = raytracer->player.dir_x * cos(-0.2) -
		raytracer->player.dir_y * sin(-0.2);
	raytracer->player.dir_y = oldirx * sin(-0.2) +
		raytracer->player.dir_y * cos(-0.2);
	oldplanex = raytracer->plane_x;
	raytracer->plane_x = raytracer->plane_x * cos(-0.2) -
		raytracer->plane_y * sin(-0.2);
	raytracer->plane_y = oldplanex * sin(-0.2) +
		raytracer->plane_y * cos(-0.2);
}

void	ft_moveleft(t_raytracer *raytracer)
{
	double	oldirx;
	double	oldplanex;

	oldirx = 0;
	oldplanex = 0;
	oldirx = raytracer->player.dir_x;
	raytracer->player.dir_x = raytracer->player.dir_x * cos(0.2) -
		raytracer->player.dir_y * sin(0.2);
	raytracer->player.dir_y = oldirx * sin(0.2) +
		raytracer->player.dir_y * cos(0.2);
	oldplanex = raytracer->plane_x;
	raytracer->plane_x = raytracer->plane_x * cos(0.2) -
		raytracer->plane_y * sin(0.2);
	raytracer->plane_y = oldplanex * sin(0.2) +
		raytracer->plane_y * cos(0.2);
}

void	ft_moveup(t_raytracer *raytracer)
{
	if (raytracer->map[(int)(raytracer->player.pos_x +
			raytracer->player.dir_x * 2)]
			[(int)(raytracer->player.pos_y)] == 0)
		raytracer->player.pos_x += raytracer->player.dir_x * 1.2;
	if (raytracer->map[(int)(raytracer->player.pos_x)]
			[(int)(raytracer->player.pos_y + raytracer->player.dir_y * 2)]
			== 0)
		raytracer->player.pos_y += raytracer->player.dir_y * 1.2;
}

void	ft_movedown(t_raytracer *raytracer)
{
	if (raytracer->map[(int)(raytracer->player.pos_x -
				raytracer->player.dir_x * 2)]
			[(int)(raytracer->player.pos_y)] == 0)
		raytracer->player.pos_x -= raytracer->player.dir_x * 1.2;
	if (raytracer->map[(int)(raytracer->player.pos_x)]
			[(int)(raytracer->player.pos_y -
				raytracer->player.dir_y * 2)] == 0)
		raytracer->player.pos_y -= raytracer->player.dir_y * 1.2;
}

int		ft_key(int k, t_raytracer *raytracer)
{
	if (k == 53)
	{
		mlx_destroy_image(raytracer->env.mlx, raytracer->env.adr);
		exit(0);
	}
	if (k == 126)
		ft_moveup(raytracer);
	if (k == 125)
		ft_movedown(raytracer);
	if (k == 123)
		ft_moveleft(raytracer);
	if (k == 124)
		ft_moveright(raytracer);
	if (k == 38)
		raytracer->jump = (raytracer->jump == 0 ? 1 : 0);
	ft_boucle(raytracer);
	mlx_put_image_to_window(raytracer->env.mlx,
			raytracer->env.win, raytracer->env.adr, 0, 0);
	mlx_string_put(raytracer->env.mlx, raytracer->env.win, 50, 5, 0xff0000,
			"Jetpack: J");
	return (0);
}
