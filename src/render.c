/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 16:09:15 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/26 12:23:16 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	auto_zoom(t_frctl *frctl)
{
	if (frctl->zoom_in == 1)
	{
		frctl->min.re = frctl->pos.re + (frctl->min.re - frctl->pos.re) * 0.8;
		frctl->max.re = frctl->pos.re + (frctl->max.re - frctl->pos.re) * 0.8;
		frctl->min.im = frctl->pos.im + (frctl->min.im - frctl->pos.im) * 0.8;
		frctl->max.im = frctl->pos.im + (frctl->max.im - frctl->pos.im) * 0.8;
	}
	if (frctl->zoom_out == 1)
	{
		frctl->min.re = frctl->pos.re + (frctl->min.re - frctl->pos.re) * 1.2;
		frctl->max.re = frctl->pos.re + (frctl->max.re - frctl->pos.re) * 1.2;
		frctl->min.im = frctl->pos.im + (frctl->min.im - frctl->pos.im) * 1.2;
		frctl->max.im = frctl->pos.im + (frctl->max.im - frctl->pos.im) * 1.2;
	}
}

static void	auto_iter_2(t_frctl *frctl)
{
	if (frctl->maxiterations < 10)
	{
		frctl->auto_iter_down = (frctl->auto_iter_down + 1) % 2;
		frctl->auto_iter_up = (frctl->auto_iter_up + 1) % 2;
	}
	else if (frctl->maxiterations > 2500)
		frctl->maxiterations -= 200;
	else if (frctl->maxiterations > 500)
		frctl->maxiterations -= 50;
	else if (frctl->maxiterations > 35)
		frctl->maxiterations -= 10;
	else
		frctl->maxiterations -= 1;
}

static void	auto_iter(t_frctl *frctl)
{
	if (frctl->auto_iter_up == 1)
	{
		if (frctl->maxiterations > 7500)
		{
			frctl->auto_iter_up = (frctl->auto_iter_up + 1) % 2;
			frctl->auto_iter_down = (frctl->auto_iter_down + 1) % 2;
		}
		else if (frctl->maxiterations > 2500)
			frctl->maxiterations += 200;
		else if (frctl->maxiterations > 500)
			frctl->maxiterations += 50;
		else if (frctl->maxiterations > 35)
			frctl->maxiterations += 10;
		else
			frctl->maxiterations += 1;
	}
	else if (frctl->auto_iter_down == 1)
		auto_iter_2(frctl);
}

int	render(t_frctl *frctl)
{	
	if (frctl->auto_iter_up == 1 || frctl->auto_iter_down == 1)
		auto_iter(frctl);
	if (frctl->zoom_in == 1 || frctl->zoom_out == 1)
		auto_zoom(frctl);
	calculate_complex_nb(frctl);
	return (0);
}
