/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:34:32 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 18:50:28 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libft_bonus.h"
#include <X11/X.h>
#include <mlx.h>
#include <stdlib.h>

// a key is pressed, it will print the key code in the terminal.
// the mouse if moved, it will print the current position of that mouse in the terminal.
// a mouse is pressed, it will print the angle at which it moved over the window to the terminal.

t_array			*g_keybinds;

static int		input_manager(int keycode, int iskeydown, void (*fp)())
{
	t_keybind	*keybind;
	size_t		i;

	if (!(keybind = malloc(sizeof(*keybind))))
		return (0);
	if (fp)
	{
		keybind->keycode = keycode;
		keybind->iskeydown = iskeydown;
		keybind->fp = fp;
		ft_array_push(g_keybinds, keybind);
	}
	else
	{
		i = 0;
		while (i < g_keybinds->size)
			if (((t_keybind *)(g_keybinds->data[i]))->keycode == keycode)
				((t_keybind *)(g_keybinds->data[i]))->fp();
	}
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
	if (!g_keybinds)
		g_keybinds = ft_make_array(0);
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
	size_t		i;

	i = 0;
	while (i < g_keybinds->size)
		if (((t_keybind *)(g_keybinds->data[i]))->keycode == keycode)
			return (((t_keybind *)(g_keybinds->data[i]))->iskeydown);
	return (0);
}
