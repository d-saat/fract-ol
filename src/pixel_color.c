/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:43:26 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/08 15:10:45 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(t_frctl *frctl, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * frctl->img.line_length + x * (frctl->img.bits_per_pixel / 8);
	dst = frctl->img.addr + offset;
	*(unsigned int *)dst = colour;
}

void	pixel_color_psychedelic(t_frctl *frctl, int n, int x, int y)
{
	double	t;
	uint8_t	rgb[3];

	t = (double)n / (double)frctl->maxiterations;
	rgb[(0 + frctl->color) % 3] = 9 * (1 - t) * t * 255;
	rgb[(1 + frctl->color) % 3] = 15 * (1 - t) * t * t * 255;
	rgb[(2 + frctl->color) % 3] = 8.5 * (1 - t) * (1 - t) * (1 - t) * 255;
	my_pixel_put(frctl, x, y, rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	pixel_color(t_frctl *frctl, int n, int x, int y)
{
	double	t;
	uint8_t	rgb[3];

	t = (double)n / (double)frctl->maxiterations;
	rgb[(0 + frctl->color) % 3] = 9 * (1 - t) * t * t * t * 255;
	rgb[(1 + frctl->color) % 3] = 15 * (1 - t) * (1 - t) * t * t * 255;
	rgb[(2 + frctl->color) % 3] = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	my_pixel_put(frctl, x, y, rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
