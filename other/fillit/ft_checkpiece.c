/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:00:53 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/16 19:29:03 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_checkpiece(t_piece *str)
{
	unsigned char x;
	unsigned char y;
	int	ret;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (str->piece[y][x] == str->letter)
				if (!(ret = ft_checkvalid(str, y, x)) 
						|| (ret == 1 && ft_checknext(str, y, x)))
					return (1);
			x++;
		}
		y++;
	}
	ft_movepiece(str);
	return (0);
}

unsigned char	ft_checknext(t_piece *str, unsigned char y, unsigned char x)
{
	if (x < 3 && str->piece[y][x + 1] == str->letter)
		if (ft_checkvalid(str, y, x + 1) < 2)
			return (1);
	if (x && str->piece[y][x - 1] == str->letter)
		if (ft_checkvalid(str, y, x - 1) < 2)
			return (1);
	if (y < 3 && str->piece[y + 1][x] == str->letter)
		if (ft_checkvalid(str, y + 1, x) < 2)
			return (1);
	if (y && str->piece[y - 1][x] == str->letter)
		if (ft_checkvalid(str, y - 1, x) < 2)
			return (1);
	return (0);
}

unsigned char ft_checkvalid(t_piece *str, unsigned char y, unsigned char x)
{
	unsigned char	counter;

	counter = 0;
	if (x < 3 && str->piece[y][x + 1] == str->letter)
		counter++;
	if (x && str->piece[y][x - 1] == str->letter)
		counter++;
	if (y < 3 && str->piece[y + 1][x] == str->letter)
		counter++;
	if (y && str->piece[y - 1][x] == str->letter)
		counter++;
	return (counter);
}

void ft_movepiece(t_piece *str)
{
	unsigned char x;
	unsigned char y;
	unsigned char movex;
	unsigned char	movey;

	y = 0;
	movey = 4;
	movex = 4;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (str->piece[y][x] == str->letter && (movex > x))
					movex = x;
			if (str->piece[y][x] == str->letter && (movey > y))
					movey = y;
			x++;
		}
		y++;
	}
	ft_movepiece2(str, movex, movey);
}

void	ft_movepiece2(t_piece *str, unsigned char movex, unsigned char movey)
{
	unsigned char x;
	unsigned char y;

	y = 0;
	str->xsize = 0;
	str->ysize = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (str->piece[y][x] == str->letter)
			{
				if (movex || movey)
				{
					str->piece[y - movey][x - movex] = str->letter;
					str->piece[y][x] = '.';
				}
				str->xsize = x - movex > str->xsize ? x - movex : str->xsize;
				str->ysize = y - movey > str->ysize ? y - movey : str->ysize;
			}
			x++;
		}
		y++;
	}
}
