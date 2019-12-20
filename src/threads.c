/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:07:33 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/01 16:39:27 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	next_color(t_obj *fractal, int pixel_position)
{
	fractal->img.data[pixel_position] = fractal->color.b +
		(unsigned char)(sin(0.016 * (FR.iter + 1.0 -
		(log(log(sqrt((ZR2) + (ZI2))))) / log(2.0)) + 4) * 200 + 55);
	fractal->img.data[pixel_position + 1] = fractal->color.g +
		(unsigned char)(sin(0.013 * (FR.iter + 1.0 -
		(log(log(sqrt((ZR2) + (ZI2))))) / log(2.0)) + 2) * 180 + 75);
	fractal->img.data[pixel_position + 2] = fractal->color.r +
		(unsigned char)(sin(0.01 * (FR.iter + 1.0 -
		(log(log(sqrt((ZR2) + (ZI2))))) / log(2.0)) + 1) * 160 + 95);
}

static void	put_pixel(t_obj *fractal)
{
	int		pixel_position;

	pixel_position = fractal->id.y * fractal->img.size_l + fractal->id.x * 4;
	if (fractal->id.x < WIN_WIDTH && fractal->id.y < WIN_HEIGHT)
	{
		if (fractal->fr.iter == fractal->fr.max_iter)
		{
			fractal->img.data[pixel_position] = 0;
			fractal->img.data[pixel_position + 1] = 0;
			fractal->img.data[pixel_position + 2] = 0;
		}
		else if (FR.color_type == 1)
			next_color(fractal, pixel_position);
		else
		{
			fractal->img.data[pixel_position] = fractal->color.b
				+ (FR.iter * 2.42);
			fractal->img.data[pixel_position + 1] = fractal->color.g
				+ (FR.iter * 2.42);
			fractal->img.data[pixel_position + 2] = fractal->color.r
				+ (FR.iter * 2.42);
		}
	}
}

static void	init_fractal(t_obj *fractal)
{
	if (fractal->fr.type == 1)
		mandelbrot(fractal);
	if (fractal->fr.type == 2)
		julia(fractal);
	if (fractal->fr.type == 3)
		burning_ship(fractal);
	if (fractal->fr.type == 4)
		ballon(fractal);
	if (fractal->fr.type == 5)
		bulbasaur(fractal);
}

static void	*render(void *data)
{
	t_obj	*fractal;

	fractal = (t_obj *)data;
	fractal->id.y = fractal->fr.start_y;
	while (fractal->id.y < fractal->fr.end_y)
	{
		fractal->id.x = 0;
		while (fractal->id.x < WIN_WIDTH)
		{
			init_fractal(fractal);
			put_pixel(fractal);
			fractal->id.x++;
		}
		fractal->id.y++;
	}
	return (data);
}

int			init_threads(t_obj *obj)
{
	t_obj		data[T_NUM];
	pthread_t	t[T_NUM];
	int			i;
	int			tmp;

	tmp = 0;
	i = 0;
	while (i < T_NUM)
	{
		ft_memcpy((void *)&data[i], (void *)obj, sizeof(t_obj));
		data[i].fr.start_y = tmp;
		tmp += WIN_HEIGHT / T_NUM;
		data[i].fr.end_y = tmp;
		pthread_create(&t[i], NULL, render, &data[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(obj->mlx.init, obj->mlx.win,
			obj->img.img_ptr, 0, 0);
	info(obj);
	return (0);
}
