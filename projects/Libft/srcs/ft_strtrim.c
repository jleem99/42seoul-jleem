/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:30 by jleem             #+#    #+#             */
/*   Updated: 2020/12/29 12:40:21 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l_idx;
	size_t	r_idx;
	char	*ret;

	l_idx = 0;
	r_idx = 0;
	while (ft_strchr(set, s1[l_idx]) && s1[l_idx])
		l_idx++;
	r_idx = l_idx;
	while (s1[r_idx])
		r_idx++;
	while (ft_strchr(set, s1[r_idx]) && r_idx != 0)
		r_idx--;
	if (l_idx > r_idx)
		return (ft_strdup(""));
	if (!(ret = malloc(sizeof(char) * (r_idx - l_idx + 2))))
		return (0);
	ft_memcpy(ret, s1 + l_idx, r_idx - l_idx + 1);
	ret[r_idx - l_idx + 1] = '\0';
	return(ret);
}
