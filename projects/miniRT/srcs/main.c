/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:53:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/06 14:53:35 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"

#include "img.h"
#include "colors.h"

#define	WIDTH	500
#define	HEIGHT	500


#include "demo.h"

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	init_img(&img);
	img_put_pixel(&img, 5, 5, 0x00FF0000);

	demo(&img, mlx, mlx_win);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// Print squares, circles, triangles and hexagons on the screen by writing the pixels accordingly;
// Try adding gradients, making rainbows, and get comfortable with using the rgb colors;
// Try making textures by generating the image in loops.
