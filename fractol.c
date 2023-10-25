/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:35:03 by mabbadi           #+#    #+#             */
/*   Updated: 2023/10/25 15:43:22 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 6) == 0)
	{
		fractal->cx = fractal->juliax;
		fractal->cy = fractal->juliay;
		draw_julia(fractal);
	}
	else
	{
		ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || argc > 4 || ((argc != 2) && (ft_strncmp(argv[1],
					"mandelbrot", 10) == 0)))
	{
		ft_putendl_fd("Available fractals: mandelbrot or julia", 1);
		ft_putendl_fd("mandelbrot with no args", 1);
		ft_putendl_fd("julia with 2 args type double", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	fractal->juliax = ft_atod(argv[2]);
	fractal->juliay = ft_atod(argv[3]);
	init_struct(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
