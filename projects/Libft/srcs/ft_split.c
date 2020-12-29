/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:18 by jleem             #+#    #+#             */
/*   Updated: 2020/12/29 12:44:03 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_chr(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_count_strs(char const *s, char c)
{
	int str_num;

	str_num = 0;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			str_num++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (str_num);
}

char		**ft_split(char const *s, char c)
{
	char		**ret;
	char const	*s_start;
	int const	str_num = ft_count_strs(s, c);
	int			str_idx;

	if (!(ret = malloc(sizeof(char *) * (str_num + 1))))
		return ((char **)0);
	str_idx = 0;
	while (str_idx < str_num)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			ret[str_idx] = malloc(ft_strlen_chr(s, c) + 1);
		s_start = s;
		while (*s != '\0' && *s != c)
		{
			ret[str_idx][s - s_start] = *s;
			s++;
		}
		ret[str_idx][s - s_start] = '\0';
		str_idx++;
	}
	ret[str_idx] = (char *)0;
	return (ret);
}
