/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:56:20 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/01 17:33:28 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int				error_input(t_obj *obj)
{
	ft_putendl("Choose fractal:");
	ft_putendl("\tmandelbrot = 1");
	ft_putendl("\tjulia = 2");
	ft_putendl("\tburningship = 3");
	ft_putendl("\tballon = 4");
	ft_putendl("\tpokemon = 5 (Who is that pokemon?)");
	ft_memdel((void **)&obj);
	exit(0);
}

int				close_win(void *param)
{
	(void)param;
	ft_memdel((void **)&param);
	exit(0);
	return (0);
}

void			error_msg(char *str)
{
	ft_putendl(str);
	exit(0);
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void			init_zoom(t_obj *obj)
{
	double	interpolation;

	interpolation = 1.0 / O_FR.scale;
	O_FR.re_factor = (O_FR.max_re - O_FR.min_re) / (WIN_WIDTH - 1);
	O_FR.im_factor = (O_FR.max_im - O_FR.min_im) / (WIN_HEIGHT - 1);
	obj->mouse.re = (O_FR.min_re + (double)obj->mouse.x_pos * O_FR.re_factor);
	obj->mouse.im = (O_FR.max_im - (double)obj->mouse.y_pos * O_FR.im_factor);
	O_FR.min_re = interpolate(obj->mouse.re, O_FR.min_re, interpolation);
	O_FR.max_re = interpolate(obj->mouse.re, O_FR.max_re, interpolation);
	O_FR.min_im = interpolate(obj->mouse.im, O_FR.min_im, interpolation);
	O_FR.max_im = interpolate(obj->mouse.im, O_FR.max_im, interpolation);
}
