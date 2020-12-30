/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:10:54 by jleem             #+#    #+#             */
/*   Updated: 2020/12/30 03:27:52 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_cur;
	t_list	*lst_tmp;

	lst_cur = *lst;
	while (lst_cur)
	{
		lst_tmp = lst_cur;
		lst_cur = lst_cur->next;
		ft_lstdelone(lst_tmp, del);
	}
	*lst = 0;
}
