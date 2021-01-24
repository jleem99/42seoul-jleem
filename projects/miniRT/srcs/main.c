/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:53:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/24 22:24:31 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "img.h"
#include "demo.h"
#include "input.h"

#define	WIDTH	500
#define	HEIGHT	500

t_mlx_global *g_global;

void	dummy(int a)
{
	printf("HEHE %d\n", a);
}

void	ft_exit()
{
	mlx_loop_end(g_global->mlx);
}

int		main(void)
{
	g_global = init_mlx_global(WIDTH, HEIGHT, "Raytracer - jleem");

	bind_input('w', 0, dummy);
	bind_input('a', 0, dummy);
	bind_input('s', 0, dummy);
	bind_input('d', 0, dummy);
	bind_input('q', 0, dummy);
	bind_input('e', 0, dummy);
	bind_input('z', 0, ft_exit);

	demo(g_global);
	free_mlx_global(g_global);
	return (0);
}

// Print squares, circles, triangles and hexagons on the screen by writing the pixels accordingly;
// Try adding gradients, making rainbows, and get comfortable with using the rgb colors;
// Try making textures by generating the image in loops.
