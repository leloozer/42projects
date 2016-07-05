/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:40:14 by mszczesn          #+#    #+#             */
/*   Updated: 2016/05/24 11:37:20 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/printf.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				z_max;
	struct s_map	*next;
	struct s_map	*previous;
}					t_map;

typedef struct		s_data
{
	struct s_map	*first;
	int				lenght_line;
	int				dh;
	int				dl;
	int				m;
	int				c;
	int				h;
	int				scale;
	int				origine_x;
	int				origine_y;
	int				fd;
	char			*line;
	char			**table;
	int				x;
	int				y;
	int				z_max;
}					t_data;

typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				map_x;
	int				map_y;
	int				x_a;
	int				y_a;
	int				x_b;
	int				y_b;
	int				j;
	t_img			img;
	struct s_data	*data;
}					t_env;

int					ft_abs(int x);
void				ft_initimg(t_env *env);
t_map				*ft_initmap(void);

void				ft_error(int i);
void				ft_map(t_data *data, t_map *map);
int					ft_parse(char *file, t_data *data);

void				ft_iso(t_env *env);

int					ft_key(int k, t_env *env);

void				ft_drawline(t_env *env, t_data *data, t_map *map);
void				ft_drawpixel(t_env *env, int x, int y, t_map *map);

#endif
