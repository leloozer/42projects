/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:24:09 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/16 19:56:30 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_getmap(t_piece **firstpiece, unsigned char *numberpiece)
{
	t_map	*map;

	if (!(map = ft_initialmap(3 + *numberpiece)))
			return (1);
	map->size = ft_mapmin(*numberpiece, firstpiece);
	while (ft_resolve(*firstpiece, map))
		map->size += 1;
	ft_printmap(map);
	free(map);
	return (0);
}

t_map	*ft_initialmap(unsigned char size)
{
	char	**charmap;
	t_map	*map;
	unsigned char x;
	unsigned char	y;

	y = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(charmap = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (y < size)
	{
		if (!(charmap[y] = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			charmap[y][x] = '.';
			x++;
		}
		y++;
	}
	map->map = charmap;
	return (map);
}

unsigned char	ft_mapmin(unsigned char numberpiece, t_piece **firstpiece)
{
	unsigned char	i;
	t_piece			*pieces;

	i = 0;
	pieces = *firstpiece;
	while ((i * i) < (numberpiece * 4))
		i++;
	while (pieces)
	{
		i = i < pieces->y + 1 ? pieces->y + 1 : i;
		i = i < pieces->x + 1 ? pieces->x + 1 : i;
		pieces = pieces->next;
	}
	return (i);
}

void	ft_printmap(t_map *map)
{
	int				x;
	int				y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			ft_putchar(map->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		free (map->map[y]);
		y++;
	}
	free(map->map);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
