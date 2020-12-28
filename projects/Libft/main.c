#include "includes/libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str = "01234";
	size_t	size = 10;

	char	*ret = ft_substr(str, 10, size);
	printf("%s|", ret);

	return (0);
}
