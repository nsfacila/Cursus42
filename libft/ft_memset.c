
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while ((size_t)i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*

int main()
{
	char str[] = "HOLA, GUAPA";
		printf("%s", ft_memset(str,'A', 3));
}*/
