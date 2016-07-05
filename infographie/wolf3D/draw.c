/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:18:03 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/13 16:47:14 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void	ft_drawpixel(t_raytracer *raytracer, int x)
{
	int		color;
	int		i;

	i = -1;
	if (raytracer->side == 0 && raytracer->mapx > 0)
		color = 0xE78F8E;
	else if (raytracer->side == 0 && raytracer->mapx <= 0)
	{
		color = 0xB3CDD1;
	}
	else if (raytracer->side == 1 && raytracer->mapy > 0)
		color = 0xfec057;
	else
		color = 0xACD8AA;
	if (raytracer->map[raytracer->mapx][raytracer->mapy] == 2)
		color = 0x000000;
	while (++i < raytracer->drawstart)
		ft_img_pixel_put(raytracer, x, i, 0xB0E0E6);
	i--;
	while (++i <= raytracer->drawend && i < raytracer->env.win_h)
		ft_img_pixel_put(raytracer, x, i, color);
	i--;
	while (++i < raytracer->env.win_h)
		ft_img_pixel_put(raytracer, x, i, 0x693300);
}

void	ft_img_pixel_put(t_raytracer *raytracer, int x, int y, int color)
{
	int		pos;

	pos = (x * 4) + (y * raytracer->env.sl);
	raytracer->env.img[pos] = color;
	raytracer->env.img[pos + 1] = (color >> 8);
	raytracer->env.img[pos + 2] = (color >> 16);
}
