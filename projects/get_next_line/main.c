/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:50:32 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 07:47:40 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char		*str;
	int	const	fd = open("test.txt", O_RDONLY);
	int			retcode;

	str = "hello";
	retcode = 1;
	while (retcode == 1)
	{
		str = 0;
		retcode = get_next_line(fd, &str);
		printf("|%d|%s|\n", retcode, str);
		free(str);
	}

	printf("\n\n\n");
	retcode = get_next_line(fd, &str);
	printf("|%d|%s|\n", retcode, str);
	free(str);

	return(0);
}
