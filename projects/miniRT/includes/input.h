/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:34:10 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 16:57:46 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

typedef struct	s_hookparam
{
	void		*mlx;
	void		*win;
}				t_hookparam;

typedef struct	s_keybind
{
	int			keycode;
	int			iskeydown;
	void		(*fp)();
}				t_keybind;

void			init_input(void *mlx, void *win);
void			bind_input(int keycode, int keydown, void (*fp)());

#endif
