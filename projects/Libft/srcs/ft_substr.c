/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:31 by jleem             #+#    #+#             */
/*   Updated: 2020/12/29 05:20:33 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen = ft_strlen(s);
	size_t	copylen;
	char	*ret;

	if (start >= slen)
		return (ft_strdup(""));
	copylen = ((slen - start) > len) ? len : (slen - start);
	if (!(ret = malloc(sizeof(char) * (copylen + 1))))
		return (0);
	ft_memcpy(ret, s + start, copylen);
	ret[copylen] = '\0';
	return (ret);
}
