/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:49 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/21 22:55:03 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *stored)
{
	char	*line;
	int		i;

	if (!stored)
		return (0);
	i = 0;
	while (stored[i] != '\n' && stored[i] != '\0')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stored[i] != '\n' && stored[i] != '\0')
	{
		line[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_stored(char *stored)
{
	int		i;
	int		j;
	char	*new_line;

	if (!stored)
		return (0);
	i = 0;
	while (stored[i] != '\n' && stored[i] != '\0')
		i++;
	if (stored[i] != '\n') // Si se encuentra un '\n',incrementar i para omitirlo 
		i++;
	new_line = ft_calloc(sizeof(char), (ft_strlen(stored) - i + 1));
	if (!new_line)
		return (0);
	j = 0;
	if (stored[i] != 0)
	{
		i++;
		while (stored[i] != 0)
			new_line[j++] = stored[i++]; //copia el resto de la cadena
	}
	new_line[j] = '\0';
	free(stored);
	return (new_line);
}

char	*ft_join_free(char *temp, char *stored)
{
	char	*aux;

	if (!stored)
	{
		stored = malloc(1);
		if (!stored)
			return (NULL);
		stored[0] = '\0';
	}
	aux = ft_strjoin(temp, stored);
	free (stored);
	return (aux);
}
/*Esta afuncion concatena dos cadenas(stored y temp), la almacena en una auxiliar, 
libera stored para que no deje memoria asiganda previamente a store que ya no necesitamos y devuelve el puntero a la candena concatenada.
La primera comprobacion de store nula, se realiza , para asignar memmoria de un colo caracter ('\0) y tenga un valor solido antes de concatenar


char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		*temp_buffer;
	static char	*stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp_buffer)
		return (0);
	read_bytes = 1;
	while (!(ft_strchr(stored, '\n')) && read_bytes > 0)
	{
		read_bytes = read (fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[read_bytes] = '\0';
		stored = ft_join_free(stored, temp_buffer);
		if (!stored)
			return (NULL);
	}
	if (read_bytes < 0)
	{
		return (free(stored), stored = NULL, NULL);
	}
	line = ft_extract_line(stored);
	stored = ft_update_stored(stored);
	return (line);
}
*/

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		temp_buffer[BUFFER_SIZE + 1];
	static char	*stored = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stored, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(stored), stored = NULL, NULL);
		temp_buffer[read_bytes] = '\0';
		stored = ft_join_free(stored, temp_buffer);
		if (!stored)
			return (NULL);
	}
	line = ft_extract_line(stored);
	stored = ft_update_stored(stored);
	return (line);
}

int main ()
{
	int	fd = open("prueba.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
