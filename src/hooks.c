/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:42:25 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/06/30 11:51:24 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	key_move(int key, t_obj *obj)
{
	O_FR.re_factor = (O_FR.max_re - O_FR.min_re) / (WIN_WIDTH / 4);
	O_FR.im_factor = (O_FR.max_im - O_FR.min_im) / (WIN_HEIGHT / 4);
	if (key == 123)
		O_FR.m_x -= O_FR.re_factor;
	if (key == 124)
		O_FR.m_x += O_FR.re_factor;
	if (key == 125)
		O_FR.m_y -= O_FR.im_factor;
	if (key == 126)
		O_FR.m_y += O_FR.im_factor;
}

static void	key_color(int key, t_obj *obj)
{
	if (key == 15)
		obj->color.r_state = (obj->color.r_state == 1) ? (0) : (1);
	if (key == 5)
		obj->color.g_state = (obj->color.g_state == 1) ? (0) : (1);
	if (key == 11)
		obj->color.b_state = (obj->color.b_state == 1) ? (0) : (1);
	if (key == 69)
	{
		obj->color.r_state == 1 ? (obj->color.r++) : (obj->color.r);
		obj->color.g_state == 1 ? (obj->color.g++) : (obj->color.g);
		obj->color.b_state == 1 ? (obj->color.b++) : (obj->color.b);
	}
	if (key == 78)
	{
		obj->color.r_state == 1 ? (obj->color.r--) : (obj->color.r);
		obj->color.g_state == 1 ? (obj->color.g--) : (obj->color.g);
		obj->color.b_state == 1 ? (obj->color.b--) : (obj->color.b);
	}
	if (key == 51)
	{
		obj->color.r = 0;
		obj->color.g = 0;
		obj->color.b = 0;
	}
}

static void	key_switch_fractal(int key, t_obj *obj)
{
	if (key == 18)
	{
		O_FR.type = 1;
		init_mandelbrot_params(obj);
	}
	if (key == 19)
	{
		O_FR.type = 2;
		init_julia_params(obj);
	}
	if (key == 20)
	{
		O_FR.type = 3;
		init_burningship_params(obj);
	}
	if (key == 21)
	{
		O_FR.type = 4;
		init_ballon_params(obj);
	}
	if (key == 23)
	{
		O_FR.type = 5;
		init_bulbasaur_params(obj);
	}
}

int			key_press(int key, t_obj *obj)
{
	key_switch_fractal(key, obj);
	key_color(key, obj);
	key_move(key, obj);
	if (key == 53)
		exit(0);
	if (key == 116 && O_FR.max_iter < 300)
	{
		O_FR.max_iter++;
		mlx_loop_hook(obj->mlx.init, &init_threads, obj);
	}
	if (key == 121 && O_FR.max_iter > 0)
	{
		O_FR.max_iter--;
		mlx_loop_hook(obj->mlx.init, &init_threads, obj);
	}
	if (key == 49)
	{
		obj->mouse.state = (obj->mouse.state == 1) ? (0) : (1);
		mlx_loop_hook(obj->mlx.init, &init_threads, obj);
	}
	if (key == 48)
		O_FR.color_type = (O_FR.color_type == 1) ? (0) : (1);
	return (0);
}
