/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:50:32 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 13:18:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#include <fcntl.h>

int		main(void)
{
	char *str;
	str = 0;

	int fd = open("test.txt", O_RDONLY);


	get_next_line(fd, &str);
	printf("|%s|\n", str);

	printf("\n\n");

	get_next_line(fd, &str);
	printf("|%s|\n", str);

	printf("\n\n");

	get_next_line(fd, &str);
	printf("|%s|\n", str);

	printf("\n\n");

	get_next_line(fd, &str);
	printf("|%s|\n", str);
}
