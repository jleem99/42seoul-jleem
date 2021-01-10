/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 18:42:47 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"


#ifndef PI
# define PI 3.14159265358979323846
#endif

#include <math.h>
#include "colors.h"
#include "mlx_global.h"
#include "engine.h"

t_img			*g_img;

void			put_pixel_interface(int x, int y, int color)
{
	img_put_pixel(g_img, x, y, color);
}

#include <stdio.h>
static void		init_demo(t_mlx_global *global)
{
	/* Setup Engine */
	t_scene		*scene = global->engine->scene;
	t_trace		*trace = global->engine->trace;

	/* Setup Objects */
	ft_array_push(scene->objects, make_sphere(make_vec3(250, 0, 0), 10, 0xffff577f));
	ft_array_push(scene->objects, make_sphere(make_vec3(500, 50, -30), 35, 0xffff884b));
	ft_array_push(scene->objects, make_sphere(make_vec3(150, -24, 20), 30, 0xffffc764));

	/* Setup Camera */
	ft_array_push(scene->cameras, make_camera(
		make_vec3(0, 0, 0),
		make_vec3(1, 0, 0),
		make_vec3(0, 0, 1),
		15.f * (float)PI / 180.f,
		make_vec2i(global->width, global->height)
	));

	g_img = global->img;
}

static void		demo_loop(t_mlx_global *global)
{
	static int	frame_count;
	t_engine	*engine;

	engine = global->engine;
	if (is_keydown('w'))
		((t_camera *)(engine->scene->cameras->data[0]))->origin.x++;
	if (is_keydown('a'))
		((t_camera *)(engine->scene->cameras->data[0]))->origin.y++;
	if (is_keydown('s'))
		((t_camera *)(engine->scene->cameras->data[0]))->origin.x--;
	if (is_keydown('d'))
		((t_camera *)(engine->scene->cameras->data[0]))->origin.y--;
	if (is_keydown('q'))
		((t_camera *)(engine->scene->cameras->data[0]))->origin.z++;
	if (is_keydown('e'))
		((t_camera *)(engine->scene->cameras->data[0]))->origin.z--;

	raytrace_with_camera(engine->trace, engine->scene->cameras->data[0], put_pixel_interface);
	mlx_put_image_to_window(global->mlx, global->win, global->img->img, 0, 0);

	printf("Frame: %07d\n", ++frame_count);
}

void			demo(t_mlx_global *global)
{
	global->engine = init_engine();
	init_demo(global);

	mlx_loop_hook(global->mlx, demo_loop, global);
	mlx_loop(global->mlx);
}
