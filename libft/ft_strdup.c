/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:49:50 by noelsanc          #+#    #+#             */
/*   Updated: 2024/05/03 18:13:07 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stddef.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	
	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
		return (ptr);
}