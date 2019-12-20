/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:40:24 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/01 17:34:05 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	parsing_bonus(t_obj *obj)
{
	if ((ft_strcmp(obj->fr.name, "burningship") == 0) ||
			(ft_strcmp(obj->fr.name, "3") == 0))
	{
		obj->fr.type = 3;
		obj->fr.name = "Burning Ship";
	}
	else if ((ft_strcmp(obj->fr.name, "ballon") == 0) ||
			(ft_strcmp(obj->fr.name, "4") == 0))
	{
		obj->fr.type = 4;
		obj->fr.name = "Ballon";
	}
	else if ((ft_strcmp(obj->fr.name, "pokemon") == 0) ||
			(ft_strcmp(obj->fr.name, "5") == 0))
	{
		obj->fr.type = 5;
		obj->fr.name = "Who is that pokemon?";
	}
	else
		return (0);
	return (1);
}

int			parsing_inputs(t_obj *obj, pid_t child_process)
{
	if ((ft_strcmp(obj->fr.name, "mandelbrot") == 0) ||
			(ft_strcmp(obj->fr.name, "1") == 0))
	{
		obj->fr.type = 1;
		obj->fr.name = "Mandelbrot";
	}
	else if ((ft_strcmp(obj->fr.name, "julia") == 0) ||
			(ft_strcmp(obj->fr.name, "2") == 0))
	{
		obj->fr.type = 2;
		obj->fr.name = "Julia";
	}
	else if (parsing_bonus(obj) == 1)
		return (1);
	else if (child_process == 0)
		error_msg("Error: Bad argument for child process");
	else
		error_input(obj);
	return (1);
}
