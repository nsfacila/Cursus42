/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcatbueno.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:54:55 by noelsanc          #+#    #+#             */
/*   Updated: 2024/05/01 11:30:52 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dest);
	i = 0;
	j = 0;
	if (len_dst >= size)
	{
		return (len_src + size);
	}
	if (size > 0 && len_dst + 1 < size)
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0' && i + j + 1 < size)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (len_dest + len_src);
}
