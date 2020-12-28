/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:19 by jleem             #+#    #+#             */
/*   Updated: 2020/12/29 03:25:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	char	*ret = malloc(size);

	if (!ret)
		return (0);
	while(*s1)
		*(ret++) = *(s1++);
	while(*s2)
		*(ret++) = *(s2++);
	*ret = '\0';
	return (ret - size + 1);
}
