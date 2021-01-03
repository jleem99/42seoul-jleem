/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:37:02 by jleem             #+#    #+#             */
/*   Updated: 2021/01/03 21:42:15 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int		color_rgba(int r, int g, int b, int a);
int		color_a(int rgba);
int		color_r(int rgba);
int		color_g(int rgba);
int		color_b(int rgba);

#endif
