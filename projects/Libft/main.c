#include "includes/libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	**ret = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	
	while (*ret)
	{
		printf("%s|", *ret);
		ret++;
	}

	return (0);
}
