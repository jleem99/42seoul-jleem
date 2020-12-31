/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:12:44 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 02:21:09 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*const	buf = malloc(nmemb * size);

	if (size == 0 || !buf)
		return (buf);
	ft_bzero(buf, nmemb * size);
	return (buf);
}
