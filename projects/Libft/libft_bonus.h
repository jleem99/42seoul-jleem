/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:33:51 by jleem             #+#    #+#             */
/*   Updated: 2021/01/09 13:32:42 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

/*
** Personal Functions (libc)
*/
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);

/*
** Personal Functions (array)
*/
typedef struct	s_array
{
	void		**data;
	size_t		size;
}				t_array;

t_array			*ft_make_array(size_t size);
void			ft_free_array(t_array *arr);
int				ft_array_push(t_array *arr, void *element);
void			*ft_array_pop(t_array *arr);

#endif
