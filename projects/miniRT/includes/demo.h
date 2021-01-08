/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:36:17 by jleem             #+#    #+#             */
/*   Updated: 2021/01/08 14:57:28 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMO_H
# define DEMO_H

# include "img.h"

typedef struct	s_demo
{
	t_img	*img;
	void	*mlx;
	void	*win;
}				t_demo;


void	demo(t_demo *s);

#endif