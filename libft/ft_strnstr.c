
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack != '\0' && len >= needle_len)
	{
		i = 0;
		while (i < needle_len && haystack[i] == needle[i])
			i++;
		if (i == needle_len)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
