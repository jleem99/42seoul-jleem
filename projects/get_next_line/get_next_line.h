/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:47 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 16:10:04 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_linestack
{
	char	*str;
	size_t	strlen;
	size_t	lines;
}				t_linestack;

int				get_next_line(int fd, char **line);

void			*ft_memcpy(void *dest, void const *src, size_t n);
size_t			ft_count_lines(char *const buf, size_t size);
void			ft_free_linestack(t_linestack *linestack);
char			*ft_linestack_pop(t_linestack *linestack);
int				ft_parse_read(t_linestack *linestack,
								char *const buf,
								size_t bytesread);

#endif
