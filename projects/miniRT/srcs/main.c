/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:53:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/17 22:03:34 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"

#include "img.h"
#include "colors.h"

#define	WIDTH	500
#define	HEIGHT	500
// #define	WIDTH	800
// #define	HEIGHT	480

#include "demo.h"
#include "input.h"
#include "mlx_global.h"

#include <stdio.h>

void	dummy(int a)
{
	printf("HEHE %d\n", a);
}

void	ft_exit()
{
	exit(0);
}

int		main(void)
{
	t_mlx_global	*global;

	global = init_mlx_global(WIDTH, HEIGHT, "Raytracer - jleem");

	bind_input('w', 0, dummy);
	bind_input('a', 0, dummy);
	bind_input('s', 0, dummy);
	bind_input('d', 0, dummy);
	bind_input('q', 0, dummy);
	bind_input('e', 0, dummy);
	bind_input('z', 0, ft_exit);

	demo(global);

	free_mlx_global(global);
	return (0);
}

// Print squares, circles, triangles and hexagons on the screen by writing the pixels accordingly;
// Try adding gradients, making rainbows, and get comfortable with using the rgb colors;
// Try making textures by generating the image in loops.
