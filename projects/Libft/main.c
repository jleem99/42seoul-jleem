#include "includes/libft.h"

int main(void)
{
	char	n[40] = "23452435232345346752345";
	int	i1 = atoi(n);
	int	i2 = ft_atoi(n);

	printf("%d\n%d\n", i1, i2);
	return (0);
}
