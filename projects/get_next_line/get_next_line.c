/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:44 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 13:34:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** handle_read
**
** [Return value]
** Should be going	1
** Should stop		0
*/

static int	handle_read(int fd, char *buf, t_line *line)
{
	int	const	readbyte = read(fd, buf, BUFFER_SIZE);

	if (readbyte == -1 || readbyte == 0)
	{
		line->retcode = readbyte;
		free(line->remainder);
		line->remainder = 0;
		line->remaindersize = 0;
	}
	else
	{
		if (ft_has_newline(buf, BUFFER_SIZE))
		{
			ft_terminate_line(line, buf); // validate return
			line->retcode = 1;
		}
		else
		{
			ft_append_line(line, buf, readbyte); // validate return
			return (1);
		}
	}
	return (0);
}
#include <stdio.h>
int			get_next_line(int fd, char **line)
{
	char			*buf;
	static t_line	line_temp;

	if (line_temp.remainder)
	{
		if (ft_has_newline(line_temp.remainder, line_temp.remaindersize))
		{
			ft_terminate_line(&line_temp, line_temp.remainder); // validate return
			*line = line_temp.buf;
			return ()
		}
		else
		{
			ft_append_line(&line_temp, buf, readbyte); // validate return
			return (1);
		}
	}








	if (!(buf = malloc(BUFFER_SIZE)))
		return (-1);
	while (handle_read(fd, buf, &line_temp))
	{
	}
	free(buf);
	*line = line_temp.buf;
	return (line_temp.retcode);
}
