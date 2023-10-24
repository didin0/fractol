/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:19:25 by mabbadi           #+#    #+#             */
/*   Updated: 2023/10/24 17:56:31 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 600

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fract
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	twoab;
	double	ca;
	double	cb;
}			t_fract;

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	juliax;
	double	juliay;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
	t_fract	*fract;
}			t_fractal;

int			draw_fractal(t_fractal *fractal, char *query);
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
void		init_mlx(t_fractal *fractal);
void		init_struct(t_fractal *fractal);
int			exit_fractal(t_fractal *fractal);
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
char		*gt(void);

#endif