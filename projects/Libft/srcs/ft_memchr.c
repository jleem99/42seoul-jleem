/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:06 by jleem             #+#    #+#             */
/*   Updated: 2020/12/28 04:07:52 by jleem            ###   ########.fr       */
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
