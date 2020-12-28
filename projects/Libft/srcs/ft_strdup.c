/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:13:16 by jleem             #+#    #+#             */
/*   Updated: 2020/12/28 21:29:50 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	size_t	size = ft_strlen(str) + 1;
	char	*copy = malloc(size);

	if (!copy)
		return (0);
	ft_memcpy(copy, str, size);
	return (copy);
}
