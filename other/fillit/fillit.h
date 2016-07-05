/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:57:51 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/16 19:51:20 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUF_SIZE (546)

typedef struct	s_map
{
	char	**map;
	unsigned char size;
}		t_map;

typedef struct	s_piece
{
	char	letter;
	unsigned char	x;
	unsigned char	y;
	unsigned char	ysize;
	unsigned char	xsize;
	char	piece[4][4];
	struct s_piece *next;
}		t_piece;

int		ft_finish(t_piece **piece);
void	ft_freepiece (t_piece *piece);
char	ft_resolve(t_piece *str, t_map *map);
char	ft_checkmap(t_piece *str, t_map *map);
void	ft_suprpiece(t_piece *str, t_map *map);
void	ft_writepiece(t_piece *str, t_map *map);
int		ft_openfile(char *file);
int		ft_getpiece(char *str, t_piece **firstpiece, unsigned char *numberpiece, int letter);
int		ft_piececonvertion(char **str, t_piece *pieces);
int		ft_getmap(t_piece **firstpiece, unsigned char *numberpiece);
t_map	*ft_initialmap(unsigned char size);
unsigned char	ft_mapmin(unsigned char numberpiece, t_piece **firstpiece);
void			ft_printmap(t_map *map);
void			ft_putchar(char c);
int				ft_checkpiece(t_piece *str);
unsigned char	ft_checknext(t_piece *str, unsigned char y, unsigned char x);
unsigned char	ft_checkvalid(t_piece *str, unsigned char y, unsigned char x);
void			ft_movepiece(t_piece *str);
void			ft_movepiece2(t_piece *str, unsigned char movex, unsigned char movey);

#endif
