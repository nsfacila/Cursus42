
#include "libft.h"

int	ft_toupper(int c)
{
	while (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}
/*
int main()
{
	char c = 'b';
	printf("%c", ft_toupper(c));
}*/
