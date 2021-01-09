/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 03:14:02 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"


#ifndef PI
# define PI 3.14159265358979323846
#endif

#include <math.h>
#include "colors.h"

#include "engine.h"

t_img			*g_img;

void			f(int x, int y, int color)
{
	img_put_pixel(g_img, x, y, color);
}

#include <stdio.h>
static void		init_demo(t_engine *engine, int width, int height)
{
	/* Setup Engine */
	t_scene		*scene = engine->scene;
	t_trace		*trace = engine->trace;

	/* Setup Objects */
	ft_array_push(scene->objects, make_sphere(make_vec3(250, 0, 0), 10, 0xffff577f));
	ft_array_push(scene->objects, make_sphere(make_vec3(500, 50, -30), 35, 0xffff884b));
	ft_array_push(scene->objects, make_sphere(make_vec3(150, -24, 20), 30, 0xffffc764));

	/* Setup Ray */
	trace->ray->origin = make_vec3(0, 0, 0);
	trace->ray->forward = make_vec3(1, 0, 0);

	/* Setup Camera */
	ft_array_push(scene->cameras, make_camera(
		make_vec3(0, 0, 0),
		make_vec3(1, 0, 0),
		make_vec3(0, 0, 1),
		15.f * (float)PI / 180.f,
		make_vec2i(width, height)
	));

	return (engine);
}

static void		demo_loop(t_engine *engine)
{
	static int	frame_count;

	raytrace_with_camera(engine->trace, engine->scene->cameras->data[0], f);
	mlx_put_image_to_window(engine->mlx, engine->mlx_win, g_img->img, 0, 0);

	printf("Frame: %07d\n", ++frame_count);
}

void			demo(t_img *img, void *mlx, void *mlx_win)
{
	t_engine	*engine = init_engine(mlx, mlx_win);
	int			width;
	int			height;

	mlx_get_screen_size(mlx, &width, &height);
	init_demo(engine, width, height);
	g_img = img;

	mlx_loop_hook(mlx, demo_loop, engine);
	mlx_loop(mlx);
}
