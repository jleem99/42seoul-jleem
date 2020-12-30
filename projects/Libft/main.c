#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
strnstr(const char *big, const char *little, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *little++) != '\0') {
		len = strlen(little);
		do {
			do {
				if (slen-- < 1 || (sc = *big++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(big, little, len) != 0);
		big--;
	}
	return ((char *)big);
}

int main(int argc, const char *argv[])
{
	printf("%s|\n", strnstr("", "12345", 5));
	printf("%s|\n", ft_strnstr("", "12345", 5));

	return (0);
}
