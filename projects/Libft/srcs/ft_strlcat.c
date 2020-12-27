/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:23 by jleem             #+#    #+#             */
/*   Updated: 2020/12/28 04:06:06 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int		ft_min(int a, int b)
// {
// 	return (a > b ? b : a);
// }

// size_t	ft_strlcat(char *dest, char const *src, size_t dest_size)
// {
// 	char *const		dest_ = dest;
// 	size_t			ret;

// 	if (dest_size == 0)
// 		return (ft_strlen(src));
// 	ret = ft_min(ft_strlen(dest), dest_size) + ft_strlen(src);
// 	while (*dest != '\0')
// 		dest++;
// 	while (*src != '\0' && (dest - dest_ + 1) < dest_size)
// 		*(dest++) = *(src++);
// 	*dest = '\0';
// 	return (ret);
// }
