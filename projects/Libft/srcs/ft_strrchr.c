/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:29 by jleem             #+#    #+#             */
/*   Updated: 2020/12/29 12:40:21 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	while (i != (size_t)-1)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
