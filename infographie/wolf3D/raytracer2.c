/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:10:52 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/13 16:04:45 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void	ft_calculdistwall(t_raytracer *raytracer)
{
	if (raytracer->side == 0)
		raytracer->walldist = (raytracer->mapx - raytracer->rayposx + (1 -
					raytracer->stepx) / 2) / raytracer->raydirx;
	else
		raytracer->walldist = (raytracer->mapy - raytracer->rayposy + (1 -
					raytracer->stepy) / 2) / raytracer->raydiry;
}

void	ft_calcullinefordraw(t_raytracer *raytracer)
{
	raytracer->lineheight = (int)(raytracer->env.win_h / raytracer->walldist);
	raytracer->drawstart = -raytracer->lineheight / 2 +
		raytracer->env.win_h / 2;
	if (raytracer->jump == 1)
		raytracer->drawstart = raytracer->drawstart + 50;
	if (raytracer->drawstart < 0)
		raytracer->drawstart = 0;
	raytracer->drawend = raytracer->lineheight / 2 + raytracer->env.win_h / 2;
	if (raytracer->jump == 1)
		raytracer->drawend = raytracer->drawend + 50;
	if (raytracer->drawend >= raytracer->env.win_h)
		raytracer->drawend = raytracer->env.win_h - 1;
}

int		ft_boucle(t_raytracer *raytracer)
{
	int	x;

	x = 0;
	while (x < raytracer->env.win_l)
	{
		ft_ray_posanddir(raytracer, x);
		ft_fordeltadist(raytracer);
		ft_calcstepandsidedist(raytracer);
		ft_searchwall(raytracer);
		ft_calculdistwall(raytracer);
		ft_calcullinefordraw(raytracer);
		ft_drawpixel(raytracer, x);
		x++;
	}
	return (0);
}
