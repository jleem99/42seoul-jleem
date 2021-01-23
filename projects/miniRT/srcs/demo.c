/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/17 23:31:33 by jleem            ###   ########.fr       */
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
	ft_array_push(scene->objects, make_sphere(make_vec3(150, 0, 30), 70, 0xffff577f));
	ft_array_push(scene->objects, make_sphere(make_vec3(200, 50, -30), 35, 0xffff884b));
	ft_array_push(scene->objects, make_sphere(make_vec3(50, -24, -20), 20, 0xffffc764));

	ft_array_push(scene->objects, make_plane(make_vec3(0, 0, -40), make_vec3(0, 0, 1), 0xffccc764));

	/* Setup Camera */
	ft_array_push(scene->cameras, make_camera(
		make_vec3(0, 0, 0),
		make_vec3(1, 0, 0),
		make_vec3(0, 0, 1),
		70.f * (float)PI / 180.f,
		make_vec2i(global->width, global->height)
	));

	g_img = global->img;
}
#include <time.h>
static void		demo_loop(t_mlx_global *global)
{
	static int	frame_count;
	t_engine	*engine = global->engine;
	t_camera	*camera = scene_get_camera(engine->scene, 0);

	if (is_keydown('w'))
		camera->origin.x++;
	if (is_keydown('a'))
		camera->origin.y--;
	if (is_keydown('s'))
		camera->origin.x--;
	if (is_keydown('d'))
		camera->origin.y++;
	if (is_keydown('q'))
		camera->origin.z--;
	if (is_keydown('e'))
		camera->origin.z++;

	raytrace_with_camera(engine->trace, camera, put_pixel_interface);

	frame_count++;
	static clock_t	last_clock;
	static double	frametime;
	static double	frametime_acc;
	frametime = (double)(clock() - last_clock) / 1000;
	frametime_acc += frametime;
	mlx_put_image_to_window(global->mlx, global->win, global->img->img, 0, 0);
	printf("Frame: %07d | Frametime: %5.2f | Frametime(avg): %5.2f\n", frame_count, frametime, frametime_acc / frame_count);
	last_clock = clock();
}

void			demo(t_mlx_global *global)
{
	global->engine = init_engine();
	init_demo(global);

	mlx_loop_hook(global->mlx, demo_loop, global);
	mlx_loop(global->mlx);
}
