/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:10:52 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 00:56:53 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"
#include "input.h"
#include "euler.h"

#include <mlx.h>
#include <stdlib.h>

extern t_mlx_global	*g_global;
double				g_frametime;

void				put_pixel_interface(int x, int y, int color)
{
	img_put_pixel(g_global->img, x, y, color);
}

static void			demo_handle_keyboard(t_mlx_global *global)
{
	t_camera		*camera = scene_get_camera(global->engine->scene, 0);
	float const		k = g_frametime * 0.1f;

	if (is_keydown('w'))
		camera->origin = vec3_add(camera->origin, vec3_mul(camera->forward, k));
	if (is_keydown('d'))
		camera->origin = vec3_add(camera->origin, vec3_mul(camera->right, k));
	if (is_keydown('e'))
		camera->origin = vec3_add(camera->origin, vec3_mul(camera->up, k));
	if (is_keydown('s'))
		camera->origin = vec3_sub(camera->origin, vec3_mul(camera->forward, k));
	if (is_keydown('a'))
		camera->origin = vec3_sub(camera->origin, vec3_mul(camera->right, k));
	if (is_keydown('q'))
		camera->origin = vec3_sub(camera->origin, vec3_mul(camera->up, k));
}

static void			demo_handle_mouse(t_mlx_global *global)
{
	int		dx;
	int		dy;

	mlx_mouse_get_pos(global->mlx, global->win, &dx, &dy);
	dx -= global->width / 2;
	dy -= global->height / 2;
	printf("Mouse delta: (%d, %d)\n", dx, dy);

	t_camera	**camera = &global->engine->scene->cameras->data[0];
	t_camera	*new_camera;
	t_vec3		d = vec3_norm((*camera)->forward);

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

void				demo_handle_input(t_mlx_global *global)
{
	demo_handle_keyboard(global);
	demo_handle_mouse(global);
	mlx_do_sync(global->mlx);
}

#include <sys/time.h>
typedef struct timeval timeval_t;
void				demo_count_frame(t_mlx_global *global)
{
	static int			frame_count;
	timeval_t			time;
	static timeval_t	time_last;
	static double		frametime;
	static double		frametime_acc;

	if (time_last.tv_sec == 0)
	{
		gettimeofday(&time_last, NULL);
		return ;
	}
	frame_count++;
	gettimeofday(&time, NULL);
	frametime = (time.tv_sec - time_last.tv_sec) * 1e3 + (time.tv_usec - time_last.tv_usec) * 1e-3;
	frametime_acc += frametime;
	printf(
		"Frame: %07d | Frametime: %5.2f | Frametime(avg): %5.2f\n",
		frame_count, frametime, frametime_acc / frame_count
	);
	g_frametime = frametime;

	gettimeofday(&time_last, NULL);
}
