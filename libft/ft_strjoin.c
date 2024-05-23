
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	int		i;
	int		j;
	char	*cat;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	cat = malloc(len_s1 + len_s2 + 1);
	if (!s1 || !s2 || !cat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		cat[i++] = s2[j++];
	}
	cat[i] = '\0';
	return (cat);
}
