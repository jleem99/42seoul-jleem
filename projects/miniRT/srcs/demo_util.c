/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:10:52 by jleem             #+#    #+#             */
/*   Updated: 2021/01/24 22:19:02 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo.h"
#include <time.h>

extern t_mlx_global	*g_global;

void				put_pixel_interface(int x, int y, int color)
{
	img_put_pixel(g_global->img, x, y, color);
}

void				demo_handle_input(t_mlx_global *global)
{
	t_camera	*camera = scene_get_camera(global->engine->scene, 0);

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
	mlx_put_image_to_window(global->mlx, global->win, global->img->img, 0, 0);
	printf(
		"Frame: %07d | Frametime: %5.2f | Frametime(avg): %5.2f\n",
		frame_count, frametime, frametime_acc / frame_count
	);
	last_clock = clock();
}
