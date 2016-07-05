/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:58:56 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/10 16:25:25 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/printf.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_env
{
	int			mandelbrot;
	int			julia;
	int			droit;
	int			burnship;
	int			tricorne;
	char		*choise;
	void		*mlx;
	void		*win;
	double		win_h;
	double		win_l;
	double		x;
	double		y;
	void		*adr;
	char		*img;
	int			bpp;
	int			sl;
	int			endian;
	double		image_x;
	double		image_y;
	double		mousex;
	double		mousey;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		imax;
	double		iteration;
	double		i;
	int			zoom;
	double		tmp;
}				t_env;

int				ft_error(int argc, char **argv, t_env *env);
void			ft_init(t_env *env);
void			ft_initimg(t_env *env);
float			ft_abs(float x);
void			ft_mlx(t_env *env);

int				ft_key(int key, t_env *env);
int				ft_mouseforzoom(int bouton, int x, int y, t_env *env);
int				ft_modifjulia(int x, int y, t_env *env);

void			ft_initfract(t_env *env);
void			ft_fractal(t_env *env);
void			ft_julia(t_env *env);
void			ft_mandelbrot(t_env *env);
void			ft_droit(t_env *env);
void			ft_burnship(t_env *env);
void			ft_tricorne(t_env *env);

void			ft_drawpixel(t_env *env);
int				ft_move(t_env *env);

#endif
