/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:42:40 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/08 14:24:06 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_complex_nb(t_frctl *frctl)
{
	int	y;
	int	x;
	int	n;

	y = 0;
	x = 0;
	n = 0;
	frctl->factor.re = (frctl->max.re - frctl->min.re) / (WIDTH - 1);
	frctl->factor.im = (frctl->max.im - frctl->min.im) / (HEIGHT - 1);
	while (y++ < HEIGHT - 1)
	{
		frctl->c.im = frctl->max.im - y * frctl->factor.im;
		x = 0;
		while (x++ < WIDTH - 1)
		{
			frctl->c.re = frctl->min.re + x * frctl->factor.re;
			n = frctl->frctl(frctl);
			frctl->color_function(frctl, n, x, HEIGHT - y);
		}
	}
	mlx_put_image_to_window(frctl->mlx.ptr, frctl->mlx.win, \
	frctl->mlx.img_ptr, 0, 0);
	if (frctl->hide_help % 2 == 0)
		help(frctl);
}

int	iterations_mandelbrot(t_frctl *frctl)
{
	t_complex	z;
	t_complex	zpow;
	int			n;

	n = 0;
	z.re = frctl->c.re;
	z.im = frctl->c.im;
	while (++n < frctl->maxiterations)
	{
		zpow.re = z.re * z.re;
		zpow.im = z.im * z.im;
		if (zpow.re + zpow.im > 4)
			break ;
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = zpow.re - zpow.im + frctl->c.re;
	}
	return (n);
}

int	iterations_julia(t_frctl *frctl)
{
	t_complex	z;
	t_complex	zpow;
	int			n;

	n = 0;
	z.re = frctl->c.re;
	z.im = frctl->c.im;
	while (++n < frctl->maxiterations)
	{
		zpow.re = z.re * z.re;
		zpow.im = z.im * z.im;
		if (zpow.re + zpow.im > 4)
			break ;
		z.im = 2 * z.re * z.im + frctl->julia.im;
		z.re = zpow.re - zpow.im + frctl->julia.re;
	}
	return (n);
}

int	iterations_burning_ship(t_frctl *frctl)
{
	t_complex	z;
	t_complex	zpow;
	int			n;

	n = 0;
	z.re = frctl->c.re;
	z.im = frctl->c.im;
	while (++n < frctl->maxiterations)
	{
		zpow.re = z.re * z.re;
		zpow.im = z.im * z.im;
		if (zpow.re + zpow.im > 4)
			break ;
		z.im = fabs(2 * z.re * z.im) + frctl->c.im;
		z.re = zpow.re - zpow.im + frctl->c.re;
	}
	return (n);
}
