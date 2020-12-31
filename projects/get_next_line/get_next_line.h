/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:47 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 13:33:33 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_line
{
	char	*buf;
	size_t	size;
	int		retcode;
	char	*remainder;
	size_t	remaindersize;
}				t_line;

int				get_next_line(int fd, char **line);

void			*ft_memcpy(void *dest, void const *src, size_t n);
int				ft_has_newline(char *buf, size_t size);
int				ft_append_line(t_line *line, char *buf, size_t appendsize);
int				ft_terminate_line(t_line *line, char *buf);

#endif
