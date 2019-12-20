/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:42:33 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/08/05 19:59:56 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static char	*out_put(t_obj *obj, int x, int y, char *str)
{
	if (str == NULL)
		return (NULL);
	mlx_string_put(obj->mlx.init, obj->mlx.win, x, y,
			0xCC0000, str);
	return (str);
}

static void	info_manipulations(t_obj *obj)
{
	out_put(obj, 450, 10, "MANIPULATIONS");
	out_put(obj, 450, 30, "Page Up/Down: change iterations");
	out_put(obj, 450, 50, "Scroll Up/Down: zoom");
	out_put(obj, 450, 70, "SPACE: mouse move lock");
	out_put(obj, 450, 90, "Use arrows for moving");
	out_put(obj, 10, 1100, "Number of iterations -> ");
	free(out_put(obj, 300, 1100, ft_itoa(obj->fr.max_iter)));
	out_put(obj, 10, 1130, "Number of zoom -> ");
	free(out_put(obj, 300, 1130, ft_itoa(obj->fr.zoom_num)));
}

static void	info_color(t_obj *obj)
{
	char	rgb_buf[15];

	ft_strcpy(rgb_buf, "R(-) G(-) B(-)");
	out_put(obj, 950, 10, "COLOR");
	rgb_buf[2] = obj->color.r_state ? '+' : '-';
	rgb_buf[7] = obj->color.g_state ? '+' : '-';
	rgb_buf[12] = obj->color.b_state ? '+' : '-';
	out_put(obj, 950, 30, rgb_buf);
	out_put(obj, 950, 50, "Backspace: reset color");
	out_put(obj, 950, 70, "+/-: change RGB parameters");
	out_put(obj, 950, 90, "TAB: change color type");
}

void		info(t_obj *obj)
{
	out_put(obj, 10, 10, "SELECT A FRACTAL");
	out_put(obj, 10, 30, "1: Mandelbrot");
	out_put(obj, 10, 50, "2: Julia Set");
	out_put(obj, 10, 70, "3: Burning Ship");
	out_put(obj, 10, 90, "4: Ballon");
	out_put(obj, 10, 110, "5: Who is that pokemon?");
	out_put(obj, 10, 130, "ESC:	exit");
	info_color(obj);
	info_manipulations(obj);
}
