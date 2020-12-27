/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:06 by jleem             #+#    #+#             */
/*   Updated: 2020/12/27 16:06:17 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *b, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return ((char *)b + i);
	return (0);
}
