/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:07:26 by noelsanc          #+#    #+#             */
/*   Updated: 2024/05/01 11:37:22 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lenght_s;
	size_t	lenght_d;
	size_t	i;

	lenght_s = ft_strlen(src);
	lenght_d = ft_strlen(dest);
	if (lenght_d >= size)
	{
		return (lenght_s + size);
	}
	if (lenght_d < size)
	{
		i = 0;
		while (src[i] != '\0' && (lenght_d + i + 1 < size))
		{
			dest[lenght_d + i] = src[i];
			i++;
		}
		dest[lenght_d + i] = '\0';
	}
	return (lenght_s + lenght_d);
}
/*
int main()
{
	char	dest[] = "Hola";
	const char	src[] = "Adios";
	size_t total = sizeof(dest);
	printf("antes:dest = %s", dest);
	printf("%zu", ft_strlcat(dest, src, total));
	printf("despues: dest %s", dest);
}*/
