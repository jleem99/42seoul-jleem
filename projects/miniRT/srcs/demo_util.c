/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:10:52 by jleem             #+#    #+#             */
/*   Updated: 2021/01/25 20:29:58 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"
#include <mlx.h>
#include <stdlib.h>
#include <time.h>
#include "euler.h"

extern t_mlx_global	*g_global;
double				g_frametime;

void				put_pixel_interface(int x, int y, int color)
{
	img_put_pixel(g_global->img, x, y, color);
}

void				demo_handle_input(t_mlx_global *global)
{
	t_camera		*camera = scene_get_camera(global->engine->scene, 0);
	float const		k = g_frametime * 0.1f;
	vec3_print(camera->forward);
	vec3_print(camera->right);
	vec3_print(camera->up);
	if (is_keydown('w'))
		camera->origin = vec3_add(camera->origin, vec3_multiply(camera->forward, k));
	if (is_keydown('d'))
		camera->origin = vec3_add(camera->origin, vec3_multiply(camera->right, k));
	if (is_keydown('e'))
		camera->origin = vec3_add(camera->origin, vec3_multiply(camera->up, k));
	if (is_keydown('s'))
		camera->origin = vec3_subtract(camera->origin, vec3_multiply(camera->forward, k));
	if (is_keydown('a'))
		camera->origin = vec3_subtract(camera->origin, vec3_multiply(camera->right, k));
	if (is_keydown('q'))
		camera->origin = vec3_subtract(camera->origin, vec3_multiply(camera->up, k));
}
#include "math.h"
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

	new_camera = make_camera(
		(*camera)->origin,
		vec3_move_euler(d, dx * 0.001f, -dy * 0.001f),
		vec3_move_euler(d, 0.f, PI / 2.f),
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
