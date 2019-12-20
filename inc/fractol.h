/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:38:09 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/30 21:19:48 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/types.h>
# include <unistd.h>
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define T_NUM 8
# define O_FR obj->fr
# define FR fractal->fr
# define ZR2 fractal->fr.z_r * fractal->fr.z_r
# define ZI2 fractal->fr.z_i * fractal->fr.z_i

typedef struct		s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		s_mouse
{
	int				state;
	int				x_pos;
	int				y_pos;
	double			re;
	double			im;
}					t_mouse;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				r_state;
	int				g_state;
	int				b_state;
	int				palette;
}					t_color;

typedef struct		s_fractal
{
	int				iter;
	int				max_iter;
	char			*name;
	int				type;
	int				start_y;
	int				end_y;
	double			scale;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			re_factor;
	double			im_factor;
	int				zoom_num;
	double			m_x;
	double			m_y;
	int				color_type;
}					t_fractal;

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*init;
	void			*win;
}					t_mlx;

typedef struct		s_obj
{
	t_mlx			mlx;
	t_img			img;
	t_fractal		fr;
	t_color			color;
	t_mouse			mouse;
	t_index			id;
}					t_obj;

/*
** parsing.c
*/
int					parsing_inputs(t_obj *obj, pid_t child_process);

/*
** threads.c
*/
int					init_threads(t_obj *obj);

/*
** fractals_types.c
*/
int					mandelbrot(t_obj *fractal);
int					julia(t_obj *fractal);
int					burning_ship(t_obj *fractal);
int					ballon(t_obj *fractal);
int					bulbasaur(t_obj *fractal);

/*
** hooks.c
*/
int					key_press(int key, t_obj *obj);

/*
** mouse.c
*/
int					mouse_press(int button, int x, int y, t_obj *obj);
int					mouse_move(int x, int y, t_obj *obj);

/*
** params.c
*/
void				init_mandelbrot_params(t_obj *obj);
void				init_julia_params(t_obj *obj);
void				init_burningship_params(t_obj *obj);
void				init_ballon_params(t_obj *obj);
void				init_bulbasaur_params(t_obj *obj);

/*
** info.c
*/
void				info(t_obj *obj);

/*
** tools.c
*/
int					close_win(void *param);
void				error_msg(char *str);
int					error_input(t_obj *obj);
void				init_zoom(t_obj *obj);

#endif
