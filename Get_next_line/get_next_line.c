/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:49 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/19 16:26:43 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stored)
{
	char	*line;
	int		i;

	if (!*stored)
		return (0);
	i = 0;
	while (stored[i] != '\n' && stored[i] != 0)
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stored[i] != '\n')
	{
		line[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static char	*ft_update_stored(char *stored)
{
	int		i;
	int		j;
	char	*new_line;

	if (!stored)
		return (0);
	i = 0;
	while (stored[i] != '\n' && stored[i] != 0)
		i++;
	new_line = ft_calloc(sizeof(char), (ft_strlen(stored) - i + 1));
	if (!new_line)
		return (0);
	j = 0;
	if (stored[i] != 0)
	{
		i++;
		while (stored[i] != 0)
			new_line[j++] = stored[i++];
	}
	new_line[j] = '\0';
	free(stored);
	return (new_line);
}

char	*join_free(char *temp, char *stored)
{
	char	*aux;

	if (!stored)
	{
		stored = malloc(1);
		if (!stored)
			return (NULL);
		stored[0] = '\0';
	}
		return (0);
	aux = ft_strjoin(temp, stored);
	free (stored);
	return (aux);
}
/*Esta afuncion concatena dos cadenas(stored y temp), la almacena en una auxiliar, 
libera stored para que no deje memoria asiganda previamente a store que ya no necesitamos y devuelve el puntero a la candena concatenada.
La primera comprobacion de store nula, se realiza , para asignar memmoria de un colo caracter ('\0) y tenga un valor solido antes de concatenar
*/

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
		stored = join_free(stored, temp_buffer);
		if (!stored)
			return (NULL);
	}
	if (read_bytes < 0)
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	line = extract_line(stored);
	stored = ft_update_stored(stored);
	return (line);
}


/*
char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(stack, '\n') && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(stack), stack = NULL, NULL);
		tmp[readbytes] = '\0';
		stack = joinfree(stack, tmp);
		if (!stack)
			return (NULL);
	}
	line = extract_line(stack);
	stack = up_stack(stack);
	return (line);
*/
int main()
{
	int	fd = open("text.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
