/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 16:42:54 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/09 14:16:18 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H 
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 600
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW	125
# define UP_ARROW 126
# define ESC 53
# define SPACE 49
# define PLUS_SIGN 24
# define MINUS_SIGN	27
# define ONE 18
# define TWO 19
# define THREE 20
# define P 35
# define R 15
# define C 8
# define H 4
# define A 0

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img_ptr;
}				t_mlx;

typedef struct s_img
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_frctl
{
	t_mlx		mlx;
	t_img		img;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	c;
	t_complex	julia;
	double		julia_pos[6][2];
	int			julia_set;
	int			maxiterations;
	int			color;
	int			isfixed;
	int			animated;
	int			hide_help;
	int			psychedelic;
	int			(*frctl)(struct s_frctl*);
	void		(*color_function)(struct s_frctl*, int, int, int);
}				t_frctl;

void	init_frctl(t_frctl *frctl);
void	init_defaults(t_frctl *frctl);

void	calculate_complex_nb(t_frctl *frctl);
int		iterations_mandelbrot(t_frctl *frctl);
int		iterations_julia(t_frctl *frctl);
int		iterations_burning_ship(t_frctl *frctl);

void	pixel_color(t_frctl *frctl, int n, int x, int y);
void	pixel_color_psychedelic(t_frctl *frctl, int n, int x, int y);

int		mouse_zoom(int button, int x, int y, t_frctl *frctl);
int		mouse_move_julia(int x, int y, t_frctl *frctl);
int		keypress(int keycode, t_frctl *frctl);

void	help(t_frctl *frctl);
char	*ftoa(double nb);

#endif