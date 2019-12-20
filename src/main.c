/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:25:24 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/08/05 19:43:50 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	init_fractal_start_params(t_obj *obj)
{
	obj->fr.iter = 0;
	obj->fr.scale = 1.00;
	obj->color.r = 0;
	obj->color.g = 0;
	obj->color.b = 0;
	obj->mouse.state = 0;
	obj->fr.m_x = 0;
	obj->fr.m_y = 0;
	if (obj->fr.type == 1)
		init_mandelbrot_params(obj);
	if (obj->fr.type == 2)
		init_julia_params(obj);
	if (obj->fr.type == 3)
		init_burningship_params(obj);
	if (obj->fr.type == 4)
		init_ballon_params(obj);
	if (obj->fr.type == 5)
		init_bulbasaur_params(obj);
}

static void	init_mlx(t_obj *obj)
{
	obj->mlx.init = mlx_init();
	obj->mlx.win = mlx_new_window(obj->mlx.init,
			WIN_WIDTH, WIN_HEIGHT, obj->fr.name);
	obj->img.img_ptr = mlx_new_image(obj->mlx.init,
			WIN_WIDTH, WIN_HEIGHT);
	obj->img.data = mlx_get_data_addr(obj->img.img_ptr,
			&obj->img.bpp, &obj->img.size_l, &obj->img.endian);
}

static void	choose_fractal(t_obj *obj, pid_t child_process)
{
	if (obj->fr.name != NULL)
	{
		parsing_inputs(obj, child_process);
		init_mlx(obj);
		init_fractal_start_params(obj);
		init_threads(obj);
	}
	else
		error_input(obj);
}

int			main(int argc, char **argv)
{
	t_obj		*obj;
	pid_t		child_process;

	child_process = -1;
	if (argc < 2 || argc > 3)
		error_msg("Error: Invalid number of input arguments");
	else
	{
		obj = (t_obj *)ft_memalloc(sizeof(t_obj));
		obj->fr.name = argv[1];
		if (argc == 3 && (child_process = fork()) == 0)
			obj->fr.name = argv[2];
		choose_fractal(obj, child_process);
		mlx_hook(obj->mlx.win, 2, 0, key_press, obj);
		mlx_hook(obj->mlx.win, 4, 0, mouse_press, obj);
		mlx_hook(obj->mlx.win, 6, 0, mouse_move, obj);
		mlx_hook(obj->mlx.win, 17, 0, close_win, obj);
		mlx_loop_hook(obj->mlx.init, &init_threads, obj);
		mlx_loop(obj->mlx.init);
	}
	return (0);
}
