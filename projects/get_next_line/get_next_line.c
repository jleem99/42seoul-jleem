/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:44 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 16:31:13 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static	t_linestack	linestack;
	char				*buf;
	ssize_t				retcode;

	if (!(buf = malloc(BUFFER_SIZE)))
		return (-1);
	retcode = 1;
	while (linestack.lines == 0 && retcode != 0)
	{
		if ((retcode = read(fd, buf, BUFFER_SIZE)) == -1)
			break ;
		ft_parse_read(&linestack, buf, retcode);
	}
	free(buf);
	if (retcode == -1 || !(*line = ft_linestack_pop(&linestack)))
		return (-1);
	if (linestack.lines == 0 && retcode == 0)
	{
		ft_free_linestack(&linestack);
		return (0);
	}
	return (1);
}
