/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:34:32 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 09:55:34 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <X11/X.h>
#include <mlx.h>
#include <stdlib.h>

#define NULL (void *)0

// a key is pressed, it will print the key code in the terminal.
// the mouse if moved, it will print the current position of that mouse in the terminal.
// a mouse is pressed, it will print the angle at which it moved over the window to the terminal.

t_keybind *g_keybinds;

static int		input_manager(int keycode, int iskeydown, void (*fp)())
{
	static int			keybind_num;
	static t_keybind	*g_keybinds;
	t_keybind			*keybinds_new;
	size_t				i;

	i = 0;
	if (fp)
	{
		if (!(keybinds_new = malloc(sizeof(*g_keybinds) * (keybind_num + 1))))
			return (0);
		while (i < keybind_num)
			keybinds_new[i] = g_keybinds[i];
		keybinds_new[i].keycode = keycode;
		keybinds_new[i].fp = fp;
		free(g_keybinds);
		g_keybinds = keybinds_new;
		keybind_num++;
	}
	else
		while (i < keybind_num)
			if (g_keybinds[i].keycode == keycode)
				fp();
	
	printf("[%d]keycode:%d|\n", iskeydown, keycode);
	return (1);
}

static void		input_hook_press(int keycode, t_hookparam *param)
{
	(void)param;
	input_manager(keycode, 1, NULL);
}

static void		input_hook_release(int keycode, t_hookparam *param)
{
	(void)param;
	input_manager(keycode, 0, NULL);
}

void			init_input(void *mlx, void *win)
{
	static t_hookparam	param;

	param.mlx = mlx;
	param.win = win;
	mlx_hook(win, KeyPress, KeyPressMask, input_hook_press, &param);
	mlx_hook(win, KeyRelease, KeyReleaseMask, input_hook_release, &param);
	mlx_do_key_autorepeatoff(mlx);
}

void			bind_input(int keycode, int keydown, void (*fp)())
{
	input_manager(keycode, keydown, fp);
}

int				is_keydown(int keycode)
{
	
}