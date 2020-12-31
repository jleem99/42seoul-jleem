/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:41 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 08:38:29 by jleem            ###   ########.fr       */
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

static char		*ft_substr(char const *s,
							size_t start,
							size_t copylen,
							int terminate)
{
	char	*ret;

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

int				ft_parse_read(t_linestack *stack,
								char const *buf,
								size_t bytesread)
{
	stack->is_eof = (bytesread == 0);
	if (stack->is_eof)
		return (1);
	if (!ft_append_buffer(&stack->str, buf, stack->strlen, bytesread))
		return (0);
	stack->strlen += bytesread;
	while (bytesread-- != 0)
		if (*buf++ == '\n')
			stack->lines++;
	return (1);
}

char			*ft_linestack_pop(t_linestack *stack)
{
	char	*pop_str;
	char	*new_str;
	size_t	len;

	len = 0;
	while (len < stack->strlen && stack->str[len] != '\n')
		len++;
	if (!(pop_str = ft_substr(stack->str, 0, len, 1)))
		return (NULL);
	stack->strlen -= len;
	if (stack->strlen != 0)
	{
		stack->lines--;
		stack->strlen--;
	}
	if (stack->strlen == 0)
		new_str = 0;
	else if (!(new_str = ft_substr(stack->str, len + 1, stack->strlen, 0)))
	{
		free(pop_str);
		return (NULL);
	}
	free(stack->str);
	stack->str = new_str;
	return (pop_str);
}
