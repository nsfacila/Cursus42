/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:10:13 by noelsanc          #+#    #+#             */
/*   Updated: 2024/05/02 18:13:16 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
/*

int main()
{
	char src[] = "hey";
	char dest[] = " Hello word";
	ft_memmove(dest, src, 2);
	printf("%s",src);
	printf("%s",dest);
}*/
