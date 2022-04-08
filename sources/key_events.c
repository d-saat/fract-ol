/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:43:02 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/08 16:40:40 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	keymove(int keycode, t_frctl *frctl)
{
	if (keycode == LEFT_ARROW)
	{
		frctl->min.re -= 25 * frctl->factor.re;
		frctl->max.re -= 25 * frctl->factor.re;
	}
	else if (keycode == RIGHT_ARROW)
	{
		frctl->min.re += 25 * frctl->factor.re;
		frctl->max.re += 25 * frctl->factor.re;
	}
	else if (keycode == UP_ARROW)
	{
		frctl->min.im -= 25 * frctl->factor.im;
		frctl->max.im -= 25 * frctl->factor.im;
	}
	else if (keycode == DOWN_ARROW)
	{
		frctl->min.im += 25 * frctl->factor.im;
		frctl->max.im += 25 * frctl->factor.im;
	}
}

static void	switch_fractol(int keycode, t_frctl *frctl)
{
	if (keycode == ONE)
		frctl->frctl = &iterations_mandelbrot;
	else if (keycode == TWO)
	{
		if (frctl->frctl == &iterations_julia)
			frctl->julia_set = (frctl->julia_set + 1) % 6;
		frctl->frctl = &iterations_julia;
		frctl->julia.re = frctl->julia_pos[frctl->julia_set][0];
		frctl->julia.im = frctl->julia_pos[frctl->julia_set][1];
	}
	else if (keycode == THREE)
		frctl->frctl = &iterations_burning_ship;
}

static int	close_program(t_frctl *frctl)
{
	mlx_destroy_window(frctl->mlx.ptr, frctl->mlx.win);
	exit (0);
}

static void	more_keypress(int keycode, t_frctl *frctl)
{
	if (keycode == P)
	{
		frctl->psychedelic = (frctl->psychedelic + 1) % 2;
		if (frctl->psychedelic == 1)
			frctl->color_function = &pixel_color_psychedelic;
		else
			frctl->color_function = &pixel_color;
	}
	if (keycode == A)
	{
		if (frctl->animated == 1)
			frctl->animated = (frctl->animated + 2) % 3;
		else
			frctl->animated = (frctl->animated + 1) % 3;
	}
}

int	keypress(int keycode, t_frctl *frctl)
{
	if (keycode == ESC)
		close_program(frctl);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW || \
		keycode == DOWN_ARROW || keycode == UP_ARROW)
		keymove(keycode, frctl);
	else if (keycode == ONE || keycode == TWO || keycode == THREE)
		switch_fractol(keycode, frctl);
	else if (keycode == PLUS_SIGN)
		frctl->maxiterations += 10;
	else if (keycode == MINUS_SIGN && frctl->maxiterations > 10)
		frctl->maxiterations -= 10;
	else if (keycode == R)
		init_defaults(frctl);
	else if (keycode == C)
		frctl->color = (frctl->color + 1) % 3;
	else if (keycode == H)
		frctl->hide_help = (frctl->hide_help + 1) % 2;
	else if (keycode == SPACE)
		frctl->isfixed = (frctl->isfixed + 1) % 2;
	else
		more_keypress(keycode, frctl);
	calculate_complex_nb(frctl);
	return (0);
}
