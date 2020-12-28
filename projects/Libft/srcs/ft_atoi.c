/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:08:54 by jleem             #+#    #+#             */
/*   Updated: 2020/12/28 21:04:50 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int num;
	int sig;

	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sig = -1;
		str++;
	}
	else
	{
		sig = 1;
		if (*str == '+')
			str++;
	}
	while (ft_isdigit(*str))
	{
		num *= 10;
		num += *(str++) - '0';
	}
	return (sig * num);
}
