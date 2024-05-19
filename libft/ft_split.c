/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:22:34 by noelsanc          #+#    #+#             */
/*   Updated: 2024/05/17 23:46:09 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words ++;
		i++;
	}
	return (words);
}

static char	*ft_givemeastr(char *s, int start, int end)
{
	char	*substr;
	int		i;

	substr = (char *)malloc((end - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

void	*ft_free(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**final;

	final = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!final)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
		{
			final[j] = ft_givemeastr((char *)s, start, i);
			if (!final[j])
			{
				ft_free(final, j);
				return (NULL);
			}
			j++;
		}
	}
	final[j] = NULL;
	return (final);
}
