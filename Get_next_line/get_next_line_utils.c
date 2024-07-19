/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:46:02 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/19 16:33:55 by noelsanc         ###   ########.fr       */
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

	result = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!result)
		return (0);
	temp = result;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
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

char	*ft_calloc(size_t size, size_t count)
{
	char	*str;
	size_t	i;

	str = malloc(count * size);
	if (!str)
		return (0);
	i = 0;
	while (i < size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
/*Asigna memoria para `count` elementos, cada uno de tamaño size.
Verifica si la asignación de memoria falló.
Inicializa manualmente la memoria a cero.
Retorna el puntero str que ahora apunta a la memoria asignada e inicializada.*/

/*
get_next_line(fd):
    static stored = ""
    buffer= leer fd
    mientras haya algo para leer:
        stored = ft_strjoin(stored, buffer)
        si ft_strchr(stored, '\n'):
            line = extraer hasta '\n' de stored
            actualizar stored sin la parte extraída
            retornar line
    retornar lo que queda en stored si no hay '\n'
*/