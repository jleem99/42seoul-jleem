/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 15:00:36 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"


#ifndef PI
# define PI 3.14159265358979323846
#endif

#include <math.h>
#include "colors.h"

#include "object.h"
#include "ray.h"
#include "scene.h"
#include "vector.h"
#include "trace.h"
#include "camera.h"

t_img	*g_img;

void	f(int x, int y, int color)
{
	img_put_pixel(g_img, x, y, color);
}

#include <stdio.h>
void	demo(t_demo *s)
{
	static int	frame_count;
	int			width;
	int			height;
	mlx_get_screen_size(s->mlx, &width, &height);
	
	printf("Frame: %07d\n", ++frame_count);
	
	/* Setup Objects */
	t_object	s1, s2, s3;

	s1 = make_sphere(make_vec3(250, 0, 0), 10, 0xffff577f);
	s2 = make_sphere(make_vec3(500, 50, -30), 35, 0xffff884b);
	s3 = make_sphere(make_vec3(150, -24, 20), 30, 0xffffc764);

	/* Setup Scene */
	t_scene		scene;

	scene = make_scene();
	scene_push_object(&scene, &s1);
	scene_push_object(&scene, &s2);
	scene_push_object(&scene, &s3);

	/* Setup Ray */
	t_ray		ray;

	ray.origin = make_vec3(0, 0, 0);
	ray.forward = make_vec3(1, 0, 0);

	/* Setup Trace */
	t_trace		trace;

	trace.scene = &scene;
	trace.ray = &ray;

	/* Setup Camera */
	t_camera	camera;

	camera = make_camera(
			make_vec3(0, 0, 0),
			make_vec3(1, 0, 0),
			make_vec3(0, 0, 1),
			15.f * (float)PI / 180.f,
			make_vec2i(width, height)
		);

	g_img = s->img;
	raytrace_with_camera(&trace, &camera, f);
	mlx_put_image_to_window(s->mlx, s->win, s->img->img, 0, 0);

	free_scene(&scene);
}
