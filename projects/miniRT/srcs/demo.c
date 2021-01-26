/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/27 00:35:31 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"
#include <mlx.h>

#ifndef PI
# define PI 3.14159265358979323846
#endif

#include <math.h>
#include "engine.h"

static void		init_demo(t_mlx_global *global)
{
	t_scene const	*scene = global->engine->scene;

	/* Setup Objects */
	ft_array_push(scene->objects, make_sphere(make_vec3(150, 0, 30), 70, 0xffff577f));
	ft_array_push(scene->objects, make_sphere(make_vec3(200, 50, -30), 35, 0xffff884b));
	ft_array_push(scene->objects, make_sphere(make_vec3(50, -24, -20), 20, 0xffffc764));

	// ft_array_push(scene->objects, make_plane(make_vec3(0, 0, -40), make_vec3(0, 0, 1), 0xffccc764));

	/* Setup Camera */
	ft_array_push(scene->cameras, make_camera(
		make_vec3(0, 0, 0),
		make_vec3(1, 0, 0),
		make_vec3(0, 0, 1),
		60.f * (float)PI / 180.f,
		make_vec2i(global->width, global->height)
	));
}

static void		demo_loop(t_mlx_global *global)
{
	demo_handle_input(global);

	raytrace_frame(global->engine);

	mlx_put_image_to_window(global->mlx, global->win, global->img->img, 0, 0);

	demo_count_frame(global);
}

void			demo(t_mlx_global *global)
{
	global->engine = init_engine(8);
	global->engine->put_pixel = put_pixel_interface;
	init_demo(global);

	mlx_loop_hook(global->mlx, demo_loop, global);
	mlx_loop(global->mlx);
	free_engine(global->engine);
}
