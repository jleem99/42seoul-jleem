/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:44:56 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 06:58:35 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"
#include <mlx.h>

void			init_img(t_img *img, void *mlx, void *win)
{
	int		width;
	int		height;

	mlx_get_screen_size(mlx, &width, &height);
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img,
									&img->bits_per_pixel,
									&img->line_length,
									&img->endian);
}

void			img_put_pixel(t_img *img, int x, int y, int color)
{
	int const	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	int *const	dst = (int *)(img->addr + offset);
	*(dst) = color;
}
