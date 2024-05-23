
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
		}
	}
	return (dst);
}

