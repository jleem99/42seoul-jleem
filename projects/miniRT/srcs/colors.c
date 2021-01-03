/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:39:10 by jleem             #+#    #+#             */
/*   Updated: 2021/01/03 21:41:30 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		color_rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int		color_a(int rgba)
{
	return (rgba & (0xFF << 24));
}

int		color_r(int rgba)
{
	return (rgba & (0xFF << 16));
}

int		color_g(int rgba)
{
	return (rgba & (0xFF << 8));
}

int		color_b(int rgba)
{
	return (rgba & 0xFF);
}
