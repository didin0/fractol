/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uwu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:46 by mabbadi           #+#    #+#             */
/*   Updated: 2023/10/24 17:55:52 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*gt(void)
{
	static char	*titles[20] = 
	{
		"Kawaii Fractals: OwO-licious Dimension Explorer",
		"Fractal Funtime: OwO's Magical Canvas",
		"UwuUniverse: A Fluffy Fractal Fiesta",
		"OwO's Whimsical World of Fractals",
		"Cuteness Overload: The Uwu Fractal Factory",
		"Rainbow Uwu Realms: Fractal Edition",
		"Adventures in OwOland: The Fractal Fantasy",
		"Uwu-tastic Fractal Dreamscape",
		"OwO's Enchanted Fractal Wonderland", "Fuzzy Fractals: Uwu Edition",
		"The Uwu-tiful Fractal Frontier", "OwO's Cosmic Fractal Odyssey",
		"Whisker-tickling Fractal Adventures: OwO Style",
		"Uwu's Kaleidoscopic Fractal Carnival",
		"OwO's Groovy Fractal Groovebox",
		"Uwu's Whirlwind of Fractal Whimsy",
		"OwO's Enigmatic Fractal Playland", "Uwu-dorable Fractal Creations",
		"Chasing Rainbows with OwO's Fractal Magic",
		"Uwuverse: The Ultimate Fractal Fantasy"
	};

	srand(time(NULL));
	return (titles[rand() % 20]);
}
