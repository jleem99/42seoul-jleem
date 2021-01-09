/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:20:24 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 19:01:46 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void			ft_free_array(t_array *arr)
{
	free(arr->data);
	free(arr);
}

void			ft_free_array_data(t_array *arr)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
		free(arr->data[i]);
}
