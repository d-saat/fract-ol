/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 16:09:15 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/09 16:51:06 by dsaat         ########   odam.nl         */
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

static void	auto_iter(t_frctl *frctl)
{
	if (frctl->auto_iter == 1)
	{
		if (frctl->maxiterations > 7500)
			frctl->auto_iter = (frctl->auto_iter + 1) % 3;
		else if (frctl->maxiterations > 2500)
			frctl->maxiterations += 200;
		else if (frctl->maxiterations > 500)
			frctl->maxiterations += 50;
		else if (frctl->maxiterations > 35)
			frctl->maxiterations += 10;
		else
			frctl->maxiterations += 1;
	}
	else if (frctl->auto_iter == 2)
	{
		if (frctl->maxiterations < 10)
			frctl->auto_iter = (frctl->auto_iter + 2) % 3;
		else if (frctl->maxiterations > 2500)
			frctl->maxiterations -= 200;
		else if (frctl->maxiterations > 500)
			frctl->maxiterations -= 50;
		else if (frctl->maxiterations > 35)
			frctl->maxiterations -= 10;
		else
			frctl->maxiterations -= 1;
	}
}

static void	auto_find(t_frctl *frctl)
{
	if (frctl->auto_find == 1)
	{
		if (frctl->julia.re < -0.753)
			frctl->julia.re += 0.001;
		if (frctl->julia.re > -0.753)
			frctl->julia.re -= 0.001;
		if (frctl->julia.im < 0.072)
			frctl->julia.im += 0.01;
		if (frctl->julia.im > 0.072)
			frctl->julia.im -= 0.01;
	}
	if (frctl->auto_find == 2)
	{
		if (frctl->julia.re < 0.23)
			frctl->julia.re += 0.01;
		if (frctl->julia.re > 0.23)
			frctl->julia.re -= 0.01;
		if (frctl->julia.im < 0.53)
			frctl->julia.im += 0.01;
		if (frctl->julia.im > 0.53)
			frctl->julia.im -= 0.01;
	}
	if (frctl->auto_find == 3)
	{
		if (frctl->julia.re < 0.3)
			frctl->julia.re += 0.001;
		if (frctl->julia.re > 0.3)
			frctl->julia.re -= 0.001;
		if (frctl->julia.im < -0.01)
			frctl->julia.im += 0.01;
		if (frctl->julia.im > -0.01)
			frctl->julia.im -= 0.01;
	}
	if (frctl->auto_find == 4)
	{
		if (frctl->julia.re < 0.28)
			frctl->julia.re += 0.01;
		if (frctl->julia.re > 0.28)
			frctl->julia.re -= 0.01;
		if (frctl->julia.im < 0.008)
			frctl->julia.im += 0.001;
		if (frctl->julia.im > 0.008)
			frctl->julia.im -= 0.001;
	}
}

int	render(t_frctl *frctl)
{	
	if (frctl->auto_iter == 1 || frctl->auto_iter == 2)
		auto_iter(frctl);
	if (frctl->zoom_in == 1 || frctl->zoom_out == 1)
		auto_zoom(frctl);
	if (frctl->auto_find > 0)
		auto_find(frctl);
	calculate_complex_nb(frctl);
	return (0);
}
