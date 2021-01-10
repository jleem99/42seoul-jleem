/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_global.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:55:00 by jleem             #+#    #+#             */
/*   Updated: 2021/01/10 18:30:40 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_GLOBAL_H
# define MLX_GLOBAL_H

# include "img.h"
# include "engine.h"

typedef struct	s_mlx_global
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_engine	*engine;
	int			width;
	int			height;
}				t_mlx_global;

t_mlx_global	*init_mlx_global(int width, int height, char const *title);
void			free_mlx_global(t_mlx_global *global);

#endif
