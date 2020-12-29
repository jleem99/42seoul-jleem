/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:08:41 by jleem             #+#    #+#             */
/*   Updated: 2020/12/29 12:40:21 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int			ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 'a' - 'A');
	else
		return (c);
}
