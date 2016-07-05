/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:54:45 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/09 15:25:57 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void	ft_ray_posanddir(t_raytracer *raytracer, int x)
{
	raytracer->rayposx = raytracer->player.pos_x;
	raytracer->rayposy = raytracer->player.pos_y;
	raytracer->camera = 2 * x / (double)raytracer->env.win_l - 1;
	raytracer->raydirx = raytracer->player.dir_x + raytracer->plane_x *
		raytracer->camera;
	raytracer->raydiry = raytracer->player.dir_y + raytracer->plane_y *
		raytracer->camera;
	raytracer->mapx = (int)raytracer->rayposx;
	raytracer->mapy = (int)raytracer->rayposy;
	raytracer->walldist = -1;
	raytracer->hit = 0;
	raytracer->side = -1;
}

void	ft_fordeltadist(t_raytracer *raytracer)
{
	raytracer->deltadistx = sqrt(1 + (raytracer->raydiry * raytracer->raydiry) /
	(raytracer->raydirx * raytracer->raydirx));
	raytracer->deltadisty = sqrt(1 + (raytracer->raydirx * raytracer->raydirx) /
	(raytracer->raydiry * raytracer->raydiry));
}

void	ft_calcstepandsidedist(t_raytracer *raytracer)
{
	if (raytracer->raydirx < 0)
	{
		raytracer->stepx = -1;
		raytracer->sidedistx = (raytracer->rayposx - raytracer->mapx) *
		raytracer->deltadistx;
	}
	else
	{
		raytracer->stepx = 1;
		raytracer->sidedistx = (raytracer->mapx + 1.0 - raytracer->rayposx) *
		raytracer->deltadistx;
	}
	if (raytracer->raydiry < 0)
	{
		raytracer->stepy = -1;
		raytracer->sidedisty = (raytracer->rayposy - raytracer->mapy) *
		raytracer->deltadisty;
	}
	else
	{
		raytracer->stepy = 1;
		raytracer->sidedisty = (raytracer->mapy + 1.0 - raytracer->rayposy) *
		raytracer->deltadisty;
	}
}

void	ft_searchwall(t_raytracer *raytracer)
{
	while (raytracer->hit == 0)
	{
		if (raytracer->sidedistx < raytracer->sidedisty)
		{
			raytracer->sidedistx += raytracer->deltadistx;
			raytracer->mapx += raytracer->stepx;
			raytracer->side = 0;
		}
		else
		{
			raytracer->sidedisty += raytracer->deltadisty;
			raytracer->mapy += raytracer->stepy;
			raytracer->side = 1;
		}
		if (raytracer->map[raytracer->mapx][raytracer->mapy] > 0)
		{
			raytracer->hit = 1;
		}
	}
}
