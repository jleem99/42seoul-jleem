/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:05 by jleem             #+#    #+#             */
/*   Updated: 2020/12/27 01:02:40 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((char *)src)[i] == c)
			return ((char *)dest + i + 1);
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (0);
}
