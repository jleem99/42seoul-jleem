/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:44 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 06:58:18 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static	t_linestack	linestack;
	char				*buf;
	ssize_t				retcode;

	if (BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE)))
		return (-1);
	retcode = 1;
	while (linestack.lines == 0 && retcode != 0)
	{
		if ((retcode = read(fd, buf, BUFFER_SIZE)) == -1 ||
			!ft_parse_read(&linestack, buf, retcode))
		{
			free(buf);
			return (-1);
		}
	}
	free(buf);
	if (linestack.strlen == 0)
	{
		*line = malloc(1);
		**line = '\0';
		return (0);
	}
	else if ((*line = ft_linestack_pop(&linestack)))
		return (retcode == 0 ? 0 : 1);
	else
		return (-1);
}
