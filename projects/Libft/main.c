#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t
strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, maxlen);
    if (dstlen == maxlen) return maxlen+srclen;
    if (srclen < maxlen-dstlen) {
        memcpy(dst+dstlen, src, srclen+1);
    } else {
        memcpy(dst+dstlen, src, maxlen-1);
        dst[dstlen+maxlen-1] = '\0';
    }
    return dstlen + srclen;
}


int main(void)
{
	char *d1 = (char *)malloc(sizeof(*d1) * 15);
	char *d2 = (char *)malloc(sizeof(*d2) * 15);
	memset(d1, 0, 15);
	memset(d1, 'r', 6);
	memset(d2, 0, 15);
	memset(d2, 'r', 6);
	d1[10] = 'a';
	d2[10] = 'a';

	int r1, r2;

	printf("|%s|%s|\n", d1, d2);

	r1 = ft_strlcat(d1, "lorem ipsum dolor sit amet", 6);
	r2 = strlcat(d2, "lorem ipsum dolor sit amet", 6);

	printf("|%d|%d|\n", r1, r2);

	printf("|%s|%s|\n", d1, d2);

	return (0);
}
