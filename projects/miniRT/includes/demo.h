/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:36:17 by jleem             #+#    #+#             */
/*   Updated: 2021/01/24 22:15:22 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMO_H
# define DEMO_H

# include "mlx_global.h"
# include <stdio.h>

void	demo(t_mlx_global *global);
void	put_pixel_interface(int x, int y, int color);
void	demo_handle_input(t_mlx_global *global);
void	demo_count_frame(t_mlx_global *global);

#endif
