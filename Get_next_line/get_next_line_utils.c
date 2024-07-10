/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:46:02 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/10 12:02:16 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		s++;
	if (*s == 0)
		return (0);
	else
		return ((char *)s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	char	*temp;

	result = malloc((ft_strlen(s1) + ft_strlen (s2)) + 1 * sizeof(char));
	if (!result)
		return (0);
	while (*s1)
	{
		*temp = *s1;
		result ++;
		s1++;
	}
	while (*s2)
	{
		*temp = *s2;
		result ++;
		s2 ++;
	}
	*temp = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
