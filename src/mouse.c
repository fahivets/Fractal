/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 11:38:17 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/06/30 11:40:45 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			mouse_move(int x, int y, t_obj *obj)
{
	if (obj->mouse.state == 1 && x > 0 && y > 0 &&
			x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		obj->mouse.x_pos = (double)x;
		obj->mouse.y_pos = (double)y;
		O_FR.c_r = (O_FR.min_re + obj->mouse.x_pos *
				(O_FR.max_re - O_FR.min_re) / (WIN_WIDTH - 1));
		O_FR.c_i = (O_FR.max_im - obj->mouse.y_pos *
				(O_FR.max_im - O_FR.min_im) / (WIN_HEIGHT - 1));
		mlx_loop_hook(obj->mlx.init, &init_threads, obj);
	}
	return (0);
}

int			mouse_press(int button, int x, int y, t_obj *obj)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		obj->mouse.x_pos = x;
		obj->mouse.y_pos = y;
		if (button == 5 && O_FR.zoom_num < 300)
		{
			O_FR.scale = 1.1;
			O_FR.zoom_num++;
			init_zoom(obj);
			mlx_loop_hook(obj->mlx.init, &init_threads, obj);
		}
		if (button == 4 && O_FR.zoom_num > -42)
		{
			O_FR.scale = 0.9;
			O_FR.zoom_num--;
			init_zoom(obj);
			mlx_loop_hook(obj->mlx.init, &init_threads, obj);
		}
	}
	return (0);
}
