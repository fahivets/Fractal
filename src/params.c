/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:07:01 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/01 15:39:26 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_bulbasaur_params(t_obj *obj)
{
	obj->fr.max_iter = 42;
	obj->fr.min_re = -2.0;
	obj->fr.max_re = 2.0;
	obj->fr.min_im = -2.0;
	obj->fr.zoom_num = 1;
	obj->fr.max_im = obj->fr.min_im +
		(obj->fr.max_re - obj->fr.min_re) * WIN_WIDTH / WIN_HEIGHT;
}

void	init_ballon_params(t_obj *obj)
{
	obj->fr.max_iter = 42;
	obj->fr.c_r = 0.57;
	obj->fr.c_i = 0.17;
	obj->fr.min_re = -2.2;
	obj->fr.max_re = 2.0;
	obj->fr.min_im = -2.2;
	obj->fr.zoom_num = 1;
	obj->fr.max_im = obj->fr.min_im +
		(obj->fr.max_re - obj->fr.min_re) * WIN_WIDTH / WIN_HEIGHT;
}

void	init_burningship_params(t_obj *obj)
{
	obj->fr.max_iter = 42;
	obj->fr.min_re = -2.2;
	obj->fr.max_re = 1.2;
	obj->fr.min_im = -1.2;
	obj->fr.zoom_num = 1;
	obj->fr.max_im = obj->fr.min_im +
		(obj->fr.max_re - obj->fr.min_re) * WIN_WIDTH / WIN_HEIGHT;
}

void	init_julia_params(t_obj *obj)
{
	obj->fr.max_iter = 42;
	obj->fr.min_re = -2.0;
	obj->fr.max_re = 2.0;
	obj->fr.min_im = -2.0;
	obj->fr.c_r = -0.7;
	obj->fr.c_i = 0.27015;
	obj->fr.zoom_num = 1;
	obj->fr.max_im = obj->fr.min_im +
		(obj->fr.max_re - obj->fr.min_re) * WIN_WIDTH / WIN_HEIGHT;
}

void	init_mandelbrot_params(t_obj *obj)
{
	obj->fr.max_iter = 42;
	obj->fr.min_re = -2.2;
	obj->fr.max_re = 0.5;
	obj->fr.min_im = -1.4;
	obj->fr.zoom_num = 1;
	obj->fr.max_im = obj->fr.min_im +
		(obj->fr.max_re - obj->fr.min_re) * WIN_WIDTH / WIN_HEIGHT;
}
