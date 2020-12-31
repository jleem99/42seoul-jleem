/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:41 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 13:33:16 by jleem            ###   ########.fr       */
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

int		ft_has_newline(char *buf, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
** <ft_append_buffer_to_line>
**
** [Return value]
** Success:	1
** Fail:	0
*/
#include <stdio.h>
int		ft_append_line(t_line *line, char *buf, size_t appendsize)
{
	char *const new_buf = malloc(line->size + appendsize);
	// printf("%s|\n", buf);
	if (!new_buf)
		return (0);
	ft_memcpy(new_buf, line->buf, line->size);
	ft_memcpy(new_buf + line->size, buf, appendsize);
	if (line->size != 0)
		free(line->buf);
	line->buf = new_buf;
	line->size += appendsize;
	return (1);
}

int		ft_terminate_line(t_line *line, char *buf)
{
	size_t	appendsize;
	size_t	remaindersize;

	appendsize = 0;
	while (buf[appendsize] != '\n')
		appendsize++;
	if (!ft_append_line(line, buf, appendsize))
		return (0);
	if (!ft_append_line(line, "", 1))
		return (0);
	remaindersize = BUFFER_SIZE - appendsize - 1;
	if (remaindersize != 0)
	{
		free(line->remainder);
		line->remainder = malloc(remaindersize + 1);
		ft_memcpy(line->remainder, buf + appendsize + 1, remaindersize);
		line->remaindersize = remaindersize;
	}
	return (1);
}
