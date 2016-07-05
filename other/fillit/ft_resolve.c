/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:14:51 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/16 19:15:05 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_resolve(t_piece *str, t_map *map)
{
	char	ret;

	str->y = 0;
	while (str->y + str->ysize < map->size)
	{
		str->x = 0;
		while (str->x + str->xsize < map->size)
		{
			if (ft_checkmap(str, map))
			{
				if (str->next)
				{
					ret = ft_resolve(str->next, map);
				}
				if (!str->next || ret == 0)
					return (0);
				ft_suprpiece(str, map);
			}
			str->x += 1;
		}
		str->y += 1;
	}
	return (1);
}

char	ft_checkmap(t_piece *str, t_map *map)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	counter;

	y = 0;
	counter = 0;
	while (y <= str->ysize)
	{
		x = 0;
		while (x <= str->xsize)
		{
			write(1, &y, 1);
			if (map->map[str->y + y][str->x + x] == '.' 
					&& str->piece[y][x] == str->letter)
				counter++;
			if (counter == 4)
			{
				ft_writepiece(str, map);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_suprpiece(t_piece *str, t_map *map)
{
	unsigned char x;
	unsigned char y;
	y = 0;
	while (y <= str->ysize)
	{
		x = 0;
		while (x <= str->xsize)
		{
			if (map->map[str->y + y][str->x + x] == str->letter)
				map->map[str->y + y][str->x + x] = '.';
			x++;
		}
		y++;
	}
}

void	ft_writepiece(t_piece *str, t_map *map)
{
	unsigned char 	x;
	unsigned char	y;

	y = 0;
	while (y <= str->ysize)
	{
		x = 0;
		while (x <= str->xsize)
		{
			if (str->piece[y][x] == str->letter)
				map->map[str->y + y][str->x + x] = str->letter;
			x++;
		}
		y++;
	}
}
