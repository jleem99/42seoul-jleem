/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:10:52 by jleem             #+#    #+#             */
/*   Updated: 2021/01/25 01:38:25 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"
#include <mlx.h>
#include <stdlib.h>
#include <time.h>

extern t_mlx_global	*g_global;
double				g_frametime;

void				put_pixel_interface(int x, int y, int color)
{
	img_put_pixel(g_global->img, x, y, color);
}

void				demo_handle_input(t_mlx_global *global)
{
	t_camera	*camera = scene_get_camera(global->engine->scene, 0);

	if (is_keydown('w'))
		camera->origin.x += g_frametime / 10;
	if (is_keydown('a'))
		camera->origin.y -= g_frametime / 10;
	if (is_keydown('s'))
		camera->origin.x -= g_frametime / 10;
	if (is_keydown('d'))
		camera->origin.y += g_frametime / 10;
	if (is_keydown('q'))
		camera->origin.z -= g_frametime / 10;
	if (is_keydown('e'))
		camera->origin.z += g_frametime / 10;
}
#include <math.h>
#ifndef PI
# define PI 3.14159265358979323846
#endif
void				demo_handle_mouse(t_mlx_global *global)
{
	int		dx;
	int		dy;

	mlx_mouse_get_pos(global->mlx, global->win, &dx, &dy);
	dx -= global->width / 2;
	dy -= global->height / 2;
	printf("Mouse delta: (%d, %d)\n", dx, dy);

	t_camera	**camera = &global->engine->scene->cameras->data[0];
	t_camera	*new_camera;
	t_vec3		d = vec3_normalize((*camera)->forward);

	float const	yaw = atan2f(d.y, d.x) + dx * (float)PI / 180.f * 0.1f;
	float const	pitch = asinf(d.z) - dy * (float)PI / 180.f * 0.1f;

	float const	new_x = cosf(yaw) * cosf(pitch);
	float const	new_y = sinf(yaw) * cosf(pitch);
	float const	new_z = sinf(pitch);

	printf("[y: %f, p: %f](%f, %f, %f) -> (%f, %f, %f)\n", yaw, pitch, d.x, d.y, d.z, new_x, new_y, new_z);

	new_camera = make_camera(
		(*camera)->origin,
		make_vec3(new_x, new_y, new_z),
		(*camera)->up,
		(*camera)->fov,
		(*camera)->viewport_dimension
	);
	free(*camera);
	*camera = new_camera;

	mlx_mouse_move(global->mlx, global->win, global->width / 2, global->height / 2);
}

void				demo_count_frame(t_mlx_global *global)
{
	static int		frame_count;
	static clock_t	last_clock;
	static double	frametime;
	static double	frametime_acc;

	frame_count++;
	frametime = (double)(clock() - last_clock) / 1000;
	frametime_acc += frametime;
	printf(
		"Frame: %07d | Frametime: %5.2f | Frametime(avg): %5.2f\n",
		frame_count, frametime, frametime_acc / frame_count
	);
	g_frametime = frametime;
	last_clock = clock();
}
