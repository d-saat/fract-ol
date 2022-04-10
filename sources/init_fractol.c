/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_fractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:42:58 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/09 17:24:55 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia_sets(t_frctl *frctl)
{
	if (frctl->frctl != &iterations_julia)
		frctl->julia_set = 0;
	frctl->julia_pos[0][0] = -0.753;
	frctl->julia_pos[0][1] = 0.072;
	frctl->julia_pos[1][0] = -0.162;
	frctl->julia_pos[1][1] = 1.04;
	frctl->julia_pos[2][0] = 0.3;
	frctl->julia_pos[2][1] = -0.01;
	frctl->julia_pos[3][0] = -1.476;
	frctl->julia_pos[3][1] = 0.0;
	frctl->julia_pos[4][0] = 0.23;
	frctl->julia_pos[4][1] = 0.53;
	frctl->julia_pos[5][0] = 0.28;
	frctl->julia_pos[5][1] = 0.008;
	frctl->julia.re = frctl->julia_pos[frctl->julia_set][0];
	frctl->julia.im = frctl->julia_pos[frctl->julia_set][1];
}

void	init_frctl(t_frctl *frctl)
{
	init_julia_sets(frctl);
	init_defaults(frctl);
	frctl->color_function = &pixel_color;
	frctl->color = 0;
	frctl->psychedelic = 0;
	frctl->isfixed = 1;
	frctl->auto_iter_up = 0;
	frctl->auto_iter_down = 0;
	frctl->hide_help = 0;
	frctl->zoom_in = 0;
	frctl->zoom_out = 0;
	frctl->auto_find = 0;
	frctl->find_set = 0;
}

void	init_defaults(t_frctl *frctl)
{
	frctl->min.re = -2.0;
	frctl->max.re = 2.0;
	frctl->min.im = -2.0;
	frctl->max.im = frctl->min.im + \
	(frctl->max.re - frctl->min.re) * HEIGHT / WIDTH;
	frctl->maxiterations = 70;
}
