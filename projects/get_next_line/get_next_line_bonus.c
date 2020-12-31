/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:44 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 08:38:04 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_next_line_from_linestack(t_linestack *stack, char **line)
{
	if (stack->strlen == 0)
	{
		*line = malloc(1);
		**line = '\0';
		return (0);
	}
	else if ((*line = ft_linestack_pop(stack)))
		return (stack->is_eof ? 0 : 1);
	else
		return (-1);
}

int			get_next_line(int fd, char **line)
{
	static	t_linestack	linestacks[OPEN_MAX];
	char				*buf;
	ssize_t				retcode;

	if (!(0 <= fd && fd < OPEN_MAX))
		return (-1);
	if (linestacks[fd].lines > 0)
		return (get_next_line_from_linestack(&linestacks[fd], line));
	if (BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE)))
		return (-1);
	retcode = 1;
	while (linestacks[fd].lines == 0 && retcode != 0)
		if ((retcode = read(fd, buf, BUFFER_SIZE)) == -1 ||
			!ft_parse_read(&linestacks[fd], buf, retcode))
		{
			free(buf);
			return (-1);
		}
	free(buf);
	return (get_next_line_from_linestack(&linestacks[fd], line));
}
