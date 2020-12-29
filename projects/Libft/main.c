#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_del(void *content)
{
	free(content);
}

void	ft_print_result(t_list * elem)
{
	printf("%s|\n", (char *)(elem->content));
}

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = ft_strdup("lorem");
	char		*str2 = ft_strdup( "ipsum");
	char		*str3 = ft_strdup( "dolor");
	char		*str4 = ft_strdup( "sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	// alarm(5);
	if (!elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	ft_lstdelone(elem3, &ft_del);
	if (elem)
		ft_print_result(elem);
	else
		write(1, "NULL\n", 5);
	write(1, "\n", 1);
	if (elem2)
		ft_print_result(elem2);
	else
		write(1, "NULL\n", 5);
	write(1, "\n", 1);
	// if (elem3)
	// 	ft_print_result(elem3);
	// else
		write(1, "NULL\n", 5);
	write(1, "\n", 1);
	if (elem4)
		ft_print_result(elem4);
	else
		write(1, "NULL\n", 5);

	return (0);
}
