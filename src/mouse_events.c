/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_events.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:43:22 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/09 14:59:01 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_frctl *frctl)
{
	double		pos_x;
	double		pos_y;
	double		zoom;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		pos_x = frctl->min.re + x * frctl->factor.re;
		pos_y = frctl->min.im + y * frctl->factor.im;
		if (button == SCROLL_UP)
			zoom = 1.2;
		else
			zoom = 0.8;
		frctl->min.re = pos_x + (frctl->min.re - pos_x) * zoom;
		frctl->max.re = pos_x + (frctl->max.re - pos_x) * zoom;
		frctl->min.im = pos_y + (frctl->min.im - pos_y) * zoom;
		frctl->max.im = pos_y + (frctl->max.im - pos_y) * zoom;
		calculate_complex_nb(frctl);
	}
	return (0);
}

int	mouse_move_julia(int x, int y, t_frctl *frctl)
{
	if (frctl->isfixed % 2 == 0)
	{
		frctl->julia.re = frctl->min.re + x * frctl->factor.re;
		frctl->julia.im = frctl->min.im + y * frctl->factor.im;
		calculate_complex_nb(frctl);
	}
	frctl->pos.re = frctl->min.re + x * frctl->factor.re;
	frctl->pos.im = frctl->min.im + y * frctl->factor.im;
	frctl->x = x;
	frctl->y = y;
	return (0);
}
