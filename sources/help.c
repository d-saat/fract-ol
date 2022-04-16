/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 12:13:22 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/08 16:57:50 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	help_julia(t_frctl *frctl)
{
	char	pos_x[20];
	char	pos_y[20];

	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, WIDTH / 2 - 50, \
	HEIGHT - 50, 0xcccccc, "space = unlock/lock");
	if (frctl->isfixed % 2 == 0)
	{
		ft_ftoa(frctl->julia.re, pos_x);
		ft_ftoa(frctl->julia.im, pos_y);
		mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, WIDTH / 2 - 16, \
		HEIGHT - 88, 0xcccccc, "x =");
		mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, WIDTH / 2 + 12, \
		HEIGHT - 88, 0xcccccc, pos_x);
		mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, WIDTH / 2 - 16, \
		HEIGHT - 74, 0xcccccc, "y =");
		mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, WIDTH / 2 + 12, \
		HEIGHT - 74, 0xcccccc, pos_y);
	}
}

void	help(t_frctl *frctl)
{
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 15, 0x444444, \
	"switch    = 1 or 2 or 3");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 29, 0x444444, \
	"zoom      = mouse scroll");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 43, 0x444444, \
	"auto zoom = W or S ");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 57, 0x444444, \
	"move      = arrow keys");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 71, 0x444444, \
	"iteration = - or +");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 85, 0x444444, \
	"auto iter = A or D");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 99, 0x444444, \
	"reset     = r");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 113, 0x444444, \
	"color     = C");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 127, 0x444444, \
	"trippy    = P");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 141, 0x444444, \
	"hide      = H");
	mlx_string_put(frctl->mlx.ptr, frctl->mlx.win, 10, 155, 0x444444, \
	"exit      = ESC");
	if (frctl->frctl == &iterations_julia)
		help_julia(frctl);
}
