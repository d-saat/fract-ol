/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:43:06 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/08 16:47:38 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	parse_input(t_frctl *frctl, int argc, char **argv)
{
	if (!argv[1])
	{
		ft_putstr("INPUT: mandelbrot || julia || burningship\n");
		exit(0);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		frctl->frctl = &iterations_mandelbrot;
	else if (ft_strcmp(argv[1], "burningship") == 0 && argc == 2)
		frctl->frctl = &iterations_burning_ship;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 3 || atoi(argv[2]) < 1 || atoi(argv[2]) > 6 \
		|| ft_strlen(argv[2]) > 1)
		{
			ft_putstr("INPUT: [julia] followed by number [1-6]\n");
			exit(0);
		}
		frctl->frctl = &iterations_julia;
		frctl->julia_set = atoi(argv[2]) - 1;
	}
	else
	{
		ft_putstr("INPUT: mandelbrot || julia || burningship\n");
		exit(0);
	}
}

static int	close_program(void)
{
	exit(0);
}

static int	render(t_frctl *frctl)
{	
	if (frctl->animated == 1)
	{
		if (frctl->maxiterations > 3500)
			frctl->animated = (frctl->animated + 1) % 3;
		else if (frctl->maxiterations > 500)
			frctl->maxiterations += 50;
		else
			frctl->maxiterations += 10;
	}
	else if (frctl->animated == 2)
	{
		if (frctl->maxiterations < 10)
			frctl->animated = (frctl->animated + 2) % 3;
		else if (frctl->maxiterations > 500)
			frctl->maxiterations -= 50;
		else if (frctl->maxiterations < 50)
			frctl->maxiterations -= 1;
		else
			frctl->maxiterations -= 10;
	}
	calculate_complex_nb(frctl);
	return (0);
}

int	main(int argc, char **argv)
{
	t_frctl	frctl;

	parse_input(&frctl, argc, argv);
	frctl.mlx.ptr = mlx_init();
	frctl.mlx.win = mlx_new_window(frctl.mlx.ptr, WIDTH, HEIGHT, "fractol");
	frctl.mlx.img_ptr = mlx_new_image(frctl.mlx.ptr, WIDTH, HEIGHT);
	frctl.img.addr = mlx_get_data_addr(frctl.mlx.img_ptr, \
	&frctl.img.bits_per_pixel, &frctl.img.line_length, &frctl.img.endian);
	init_frctl(&frctl);
	calculate_complex_nb(&frctl);
	mlx_hook(frctl.mlx.win, 2, 0, keypress, &frctl);
	mlx_hook(frctl.mlx.win, 6, 0, mouse_move_julia, &frctl);
	mlx_hook(frctl.mlx.win, 17, 0, close_program, &frctl);
	mlx_mouse_hook(frctl.mlx.win, mouse_zoom, &frctl);
	mlx_loop_hook(frctl.mlx.ptr, render, &frctl);
	mlx_loop(frctl.mlx.ptr);
	return (0);
}
