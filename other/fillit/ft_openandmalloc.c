/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openandmalloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:01:16 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/16 19:17:12 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_openfile(char *file)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];
	unsigned char *numberpiece;
	t_piece	**firstpiece;

	numberpiece = (unsigned char *)malloc(sizeof(unsigned char));
	if ((fd = open(file, O_RDONLY)) == -1 || !numberpiece)
		return (1);
	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		return (1);
	if (close(fd) == -1) 
		return (1);
		if (ret > 545)
		return (1);
	buf[ret] = '\0';
	if (!(firstpiece = (t_piece**)malloc(sizeof(t_piece*))))
		return (2);
	ret = 'A';
	if (ft_getpiece(buf, firstpiece, numberpiece, ret) || ft_getmap(firstpiece, numberpiece))
		return (1);
	ft_finish(firstpiece);
	free(numberpiece);
	return (0);
}

int	ft_getpiece(char *str, t_piece **firstpiece, unsigned char *numberpiece, int letter)
{
	t_piece	*pieces;
	if (!(pieces = (t_piece*)malloc(sizeof(t_piece))))
		return (2);
	pieces->letter = letter;
	if (ft_piececonvertion(&str, pieces) || ft_checkpiece(pieces))
		return (1);
	*firstpiece = pieces;
	while (*str)
	{
		letter++;
		if (*str != '\n')
			return (1);
		str += 1;
		if (!*str)
			return (1);
		if (!(pieces->next = (t_piece*)malloc(sizeof(t_piece))))
			return (2);
		pieces = pieces->next;
		pieces->letter = letter;
		if (ft_piececonvertion(&str, pieces) || ft_checkpiece(pieces))
			return (1);
	}
	*numberpiece = letter + 1 - 'A';
	return (0);
}

int ft_piececonvertion(char **str, t_piece *pieces)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	counter;

	y = 0;
	counter = 0;
	pieces->next = NULL;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			**str == '#' ? counter++ : counter;
			if ((**str != '.' && **str != '#') || counter > 4)
				return (1);
			pieces->piece[y][x] = **str == '#' ? pieces->letter : '.';
			x++;
			*str += 1;
		}
		if (**str != '\n')
			return (1);
		*str += 1;
		y++;
	}
	return (counter != 4 ? 1 : 0);
}

