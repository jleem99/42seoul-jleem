/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:39:19 by jleem             #+#    #+#             */
/*   Updated: 2021/01/07 07:49:29 by jleem            ###   ########.fr       */
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
#include <stdio.h>

void	print_circle(t_img *img, int sx, int sy, int sr, int color)
{
	double rad = 0;
	double r = sr;
	int x, y;

	while (r > 0)
	{
		rad = 0;
		while (rad < PI * 2)
		{
			x = sx + r * cos(rad);
			y = sy + r * sin(rad);
			img_put_pixel(img, x, y, color);
			rad += 0.1;
		}
		r -= 1;
		printf("r:%f|\n", r);
	}
}


t_img	*g_img;

void	f(int x, int y, int color)
{
	img_put_pixel(g_img, x, y, color);
}


void	demo(t_img *img, void *mlx, void *win)
{
	(void)mlx;
	(void)win;
	(void)img;

	// print_circle(img, 250, 250, 50, 0xFFFAAFF);

	/* Setup Objects */
	t_object	s1, s2, s3;

	s1.location = make_vec3(250, 0, 0);
	s2.location = make_vec3(500, 50, -30);
	s3.location = make_vec3(150, -24, 20);

	s1.radius = 10;
	s2.radius = 35;
	s3.radius = 30;

	s1.forward = make_vec3(0, 0, 1);
	s2.forward = make_vec3(0, 0, 1);
	s3.forward = make_vec3(0, 0, 1);

	s1.type = sphere;
	s2.type = sphere;
	s3.type = sphere;

	s1.color = 0xffff577f;
	s2.color = 0xffff884b;
	s3.color = 0xffffc764;

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
			20.f * (float)PI / 180.f,
			make_vec2i(500, 500)
		);

	g_img = img;

	// for (size_t i = 0; i < 500; i++)
	// {
	// 	for (size_t j = 0; j < 500; j++)
	// 	{
	// 		trace.ray->forward = make_vec3(1, 0.1 * ((float)i - 250) / 10, 0.1 * ((float)j - 250));
	// 		trace.count = 1;
	// 		raytrace(&trace);
	// 		img_put_pixel(img, i, j, trace.color);
	// 	}
	// }
	raytrace_with_camera(&trace, &camera, f);
	
	printf("Done\n");
}
