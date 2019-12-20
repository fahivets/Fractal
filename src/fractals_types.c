/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:35:45 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/01 17:15:13 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		mandelbrot(t_obj *fractal)
{
	double	tmp_z_r;
	double	z_rsqr;
	double	z_isqr;

	FR.re_factor = (FR.max_re - FR.min_re) / (WIN_WIDTH - 1);
	FR.im_factor = (FR.max_im - FR.min_im) / (WIN_HEIGHT - 1);
	FR.c_r = (FR.min_re + (double)fractal->id.x * FR.re_factor) + FR.m_x;
	FR.c_i = (FR.max_im - (double)fractal->id.y * FR.im_factor) + FR.m_y;
	FR.z_r = 0;
	FR.z_i = 0;
	FR.iter = 0;
	while (FR.iter < FR.max_iter)
	{
		tmp_z_r = FR.z_r;
		z_rsqr = FR.z_r * FR.z_r;
		z_isqr = FR.z_i * FR.z_i;
		FR.z_r = z_rsqr - z_isqr + FR.c_r;
		FR.z_i = 2.0 * FR.z_i * tmp_z_r + FR.c_i;
		if (z_rsqr + z_isqr > 4.0)
			break ;
		FR.iter++;
	}
	return (FR.iter);
}

int		julia(t_obj *fractal)
{
	double	tmp_z_r;
	double	z_rsqr;
	double	z_isqr;

	FR.re_factor = (FR.max_re - FR.min_re) / (WIN_WIDTH - 1);
	FR.im_factor = (FR.max_im - FR.min_im) / (WIN_HEIGHT - 1);
	FR.z_r = (FR.min_re + (double)fractal->id.x * FR.re_factor) + FR.m_x;
	FR.z_i = (FR.max_im - (double)fractal->id.y * FR.im_factor) + FR.m_y;
	FR.iter = 0;
	while (FR.iter < FR.max_iter)
	{
		tmp_z_r = FR.z_r;
		z_rsqr = FR.z_r * FR.z_r;
		z_isqr = FR.z_i * FR.z_i;
		FR.z_r = z_rsqr - z_isqr + FR.c_r;
		FR.z_i = 2.0 * FR.z_i * tmp_z_r + FR.c_i;
		if (z_rsqr + z_isqr > 4.0)
			break ;
		FR.iter++;
	}
	return (FR.iter);
}

int		burning_ship(t_obj *fractal)
{
	double	tmp_z_r;
	double	z_rsqr;
	double	z_isqr;

	FR.re_factor = (FR.max_re - FR.min_re) / (WIN_WIDTH - 1);
	FR.im_factor = (FR.max_im - FR.min_im) / (WIN_HEIGHT - 1);
	FR.c_r = (FR.min_re + (double)fractal->id.x * FR.re_factor) + FR.m_x;
	FR.c_i = (FR.max_im - (double)fractal->id.y * FR.im_factor) + FR.m_y;
	FR.z_r = 0;
	FR.z_i = 0;
	FR.iter = 0;
	while (FR.iter < FR.max_iter)
	{
		tmp_z_r = FR.z_r;
		z_rsqr = FR.z_r * FR.z_r;
		z_isqr = FR.z_i * FR.z_i;
		FR.z_r = z_rsqr - z_isqr + FR.c_r;
		FR.z_i = 2.0 * fabs(FR.z_i * tmp_z_r) - FR.c_i;
		if (z_rsqr + z_isqr > 4.0)
			break ;
		FR.iter++;
	}
	return (FR.iter);
}

int		ballon(t_obj *fractal)
{
	double	tmp_z_r;
	double	z_rsqr;
	double	z_isqr;
	double	calculations;

	FR.re_factor = (FR.max_re - FR.min_re) / (WIN_WIDTH - 1);
	FR.im_factor = (FR.max_im - FR.min_im) / (WIN_HEIGHT - 1);
	FR.z_r = (FR.min_re + (double)fractal->id.x * FR.re_factor) + FR.m_x;
	FR.z_i = (FR.max_im - (double)fractal->id.y * FR.im_factor) + FR.m_y;
	FR.iter = 0;
	while (FR.iter < FR.max_iter)
	{
		tmp_z_r = FR.z_r;
		z_rsqr = FR.z_r * FR.z_r;
		z_isqr = FR.z_i * FR.z_i;
		calculations = (z_rsqr * (z_rsqr + 2.0 * z_isqr + 2.0 * FR.c_r)) +
		(z_isqr * (z_isqr - (2.0 * FR.c_r))) + (4.0 *
		(FR.z_r * FR.z_i * FR.c_i) + pow(FR.c_i, 2.0) + pow(FR.c_r, 2.0));
		FR.z_r = (z_rsqr - z_isqr + FR.c_r) / calculations;
		FR.z_i = -(2.0 * tmp_z_r * FR.z_i + FR.c_i) / calculations;
		if (z_rsqr + z_isqr > 4.0)
			break ;
		FR.iter++;
	}
	return (FR.iter);
}

int		bulbasaur(t_obj *fractal)
{
	double	z_r4;
	double	z_i4;
	double	zr_zisqr;

	FR.re_factor = (FR.max_re - FR.min_re) / (WIN_WIDTH - 1);
	FR.im_factor = (FR.max_im - FR.min_im) / (WIN_HEIGHT - 1);
	FR.c_r = (FR.min_re + (double)fractal->id.x * FR.re_factor) + FR.m_x;
	FR.c_i = (FR.max_im - (double)fractal->id.y * FR.im_factor) + FR.m_y;
	FR.z_r = 0;
	FR.z_i = 0;
	FR.iter = 0;
	while (FR.iter < FR.max_iter)
	{
		z_r4 = FR.z_r * FR.z_r * FR.z_r * FR.z_r;
		z_i4 = FR.z_i * FR.z_i * FR.z_i * FR.z_i;
		zr_zisqr = (FR.z_r * FR.z_r) * (FR.z_i * FR.z_i);
		FR.z_r = fabs(FR.z_r) * (z_r4 - 10 * zr_zisqr + 5 * z_i4) + FR.c_r;
		FR.z_i = fabs(FR.z_i) * (5 * z_r4 - 10 * zr_zisqr + z_i4) + FR.c_i;
		if ((FR.z_r * FR.z_r) + (FR.z_i * FR.z_i) > 4.0)
			break ;
		FR.iter++;
	}
	return (FR.iter);
}
