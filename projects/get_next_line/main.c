/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:50:32 by jleem             #+#    #+#             */
/*   Updated: 2020/12/31 16:30:50 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char		*str;
	int	const	fd = open("test.txt", O_RDONLY);

	str = 0;
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	printf("\n\n");
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	printf("\n\n");
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	printf("\n\n");
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	printf("\n\n");
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	printf("\n\n");
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	printf("\n\n");
	get_next_line(fd, &str);
	printf("|%s|\n", str);
	free(str);
	// free(str);

	return(0);
}
