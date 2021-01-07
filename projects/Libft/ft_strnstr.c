/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:28 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 04:37:40 by jleem            ###   ########.fr       */
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
