/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:28 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 00:40:37 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	const	little_len = ft_strlen(little);
	size_t			i;

	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	while (big[i] != *little)
		if (big[i++] == '\0')
			return (0);
	while (i + little_len <= len && big[i])
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
