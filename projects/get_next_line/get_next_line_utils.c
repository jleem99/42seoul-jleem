/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:41 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 06:58:52 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = -1;
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

static char		*ft_substr(char const *s, size_t start, size_t copylen, int terminate)
{
	char			*ret;

	if (!(ret = malloc(sizeof(*ret) * (copylen + (terminate ? 1 : 0)))))
		return (0);
	ft_memcpy(ret, s + start, copylen);
	if (terminate)
		ret[copylen] = '\0';
	return (ret);
}

static int		ft_append_buffer(char **dst, char const *buf,
								size_t dstsize, size_t bufsize)
{
	char	*new_dst;

	if (!(new_dst = malloc(dstsize + bufsize)))
		return (0);
	ft_memcpy(new_dst, *dst, dstsize);
	ft_memcpy(new_dst + dstsize, buf, bufsize);
	free(*dst);
	*dst = new_dst;
	return (1);
}

int				ft_parse_read(t_linestack *linestack,
								char const *buf,
								size_t bytesread)
{
	if (bytesread == 0)
		return (1);
	if (!ft_append_buffer(&linestack->str, buf, linestack->strlen, bytesread))
		return (0);
	linestack->strlen += bytesread;
	while (bytesread-- != 0)
		if (*buf++ == '\n')
			linestack->lines++;
	return (1);
}

char			*ft_linestack_pop(t_linestack *linestack)
{
	char	*pop_str;
	char	*new_str;
	size_t	len;

	len = 0;
	while (len < linestack->strlen && linestack->str[len] != '\n')
		len++;
	if (!(pop_str = ft_substr(linestack->str, 0, len, 1)))
		return (NULL);
	linestack->strlen -= len;
	if (linestack->strlen != 0)
	{
		linestack->lines--;
		linestack->strlen--;
	}
	if (linestack->strlen == 0)
		new_str = 0;
	else if (!(new_str = ft_substr(linestack->str, len + 1, linestack->strlen, 0)))
	{
		free(pop_str);
		return (NULL);
	}
	free(linestack->str);
	linestack->str = new_str;
	return (pop_str);
}
