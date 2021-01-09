/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:53:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 16:01:34 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"

#include "img.h"
#include "colors.h"

#define	WIDTH	700
#define	HEIGHT	500


#include "demo.h"
#include "input.h"

#include <stdio.h>

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");

	init_img(&img, mlx, mlx_win);
	init_input(mlx, mlx_win);

	t_demo	s;
	s.img = &img;
	s.mlx = mlx;
	s.win = mlx_win;

	// for (size_t i = 0; i < 50; i++)
		// demo(&s);

	mlx_loop_hook(mlx, demo, &s);
	mlx_loop(mlx);

	return (0);
}

// Print squares, circles, triangles and hexagons on the screen by writing the pixels accordingly;
// Try adding gradients, making rainbows, and get comfortable with using the rgb colors;
// Try making textures by generating the image in loops.
