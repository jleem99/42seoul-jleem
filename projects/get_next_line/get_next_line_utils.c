/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:41 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 15:06:58 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = -1;
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

size_t	ft_count_lines(char *const buf, size_t size)
{
	size_t	lines;
	size_t	i;

	lines = 0;
	i = 0;
	while (i < size)
		if (buf[i++] == '\n')
			lines++;
	return (lines);
}

void	ft_free_linestack(t_linestack *linestack)
{
	free(linestack->str);
	linestack->str = 0;
	linestack->strlen = 0;
	linestack->lines = 0;
}

char	*ft_linestack_pop(t_linestack *linestack)
{
	char	*ret;
	char	*new_str;
	size_t	len;

	len = 0;
	while (linestack->str[len] != '\n' && len < linestack->strlen)
		len++;
	linestack->strlen -= len;
	if (linestack->lines != 0)
	{
		linestack->lines--;
		linestack->strlen--;
	}
	if (!(ret = malloc(len + 1)))
		return (NULL);
	ft_memcpy(ret, linestack->str, len);
	if (!(new_str = malloc(linestack->strlen)))
		return (NULL);
	ft_memcpy(new_str, linestack->str + len + 1, linestack->strlen);
	free(linestack->str);
	linestack->str = new_str;
	ret[len] = '\0';
	return (ret);
}

int		ft_parse_read(t_linestack *linestack, char *const buf, size_t bytesread)
{
	char	*new_str;

	if (!(new_str = malloc(linestack->strlen + bytesread)))
		return (0);
	ft_memcpy(new_str, linestack->str, linestack->strlen);
	ft_memcpy(new_str + linestack->strlen, buf, bytesread);
	free(linestack->str);
	linestack->str = new_str;
	linestack->strlen += bytesread;
	linestack->lines += ft_count_lines(buf, bytesread);
	return (1);
}
