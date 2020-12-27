/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:10 by jleem             #+#    #+#             */
/*   Updated: 2020/12/27 16:06:17 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t	i;
	char	temp_buf[n];

	i = -1;
	while (++i < n)
		temp_buf[i] = ((char *)src)[i];
	i = -1;
	while (++i < n)
		((char *)dest)[i] = temp_buf[i];
	return (dest);
}
