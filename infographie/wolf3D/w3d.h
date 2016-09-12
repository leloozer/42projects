/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:11:55 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/13 17:57:30 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_H
# define W3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/printf.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_player
{
	int			pos_x;
	int			pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			bpp;
	int			sl;
	int			endian;
	char		*img;
	void		*adr;
	int			win_h;
	int			win_l;
}				t_env;

typedef struct	s_raytracer
{
	char		*choise;
	int			size;
	int			jump;
	double		plane_x;
	double		plane_y;
	double		time;
	double		oldtime;
	double		camera;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		movespeed;
	double		rotspeed;
	double		stepx;
	double		stepy;
	int			mapx;
	int			mapy;
	int			**map;
	double		walldist;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	t_player	player;
	t_env		env;
}				t_raytracer;

int				ft_key(int k, t_raytracer *raytracer);
int				ft_mouse(int x, int y);

void			ft_initraytracer(t_raytracer *raytracer);
void			ft_ray_posanddir(t_raytracer *raytracer, int x);
void			ft_fordeltadist(t_raytracer *raytracer);
void			ft_calcstepandsidedist(t_raytracer *raytracer);
void			ft_searchwall(t_raytracer *raytracer);
void			ft_calculdistwall(t_raytracer *raytracer);
int				ft_boucle(t_raytracer *raytracer);

void			ft_drawpixel(t_raytracer *raytracer, int x);
void			ft_img_pixel_put(t_raytracer *raytracer,
				int x, int y, int color);

char			*ft_lvl1(t_raytracer *raytracer);
char			*ft_lvl2(t_raytracer *raytracer);
char			*ft_lvl3(t_raytracer *raytracer);
char			*ft_lvl4(t_raytracer *raytracer);
char			*ft_lvl5(t_raytracer *raytracer);
#endif
