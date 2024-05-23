
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	if (s1 [start] == 0)
		return (ft_strdup(""));
	end = ft_strlen(s1);
	while (ft_strchr (set, s1[start]))
		start++;
	while (ft_strchr (set, s1[end]))
		end--;
	str = ft_substr (s1, start, (end - start) + 1);
	return (str);
}
