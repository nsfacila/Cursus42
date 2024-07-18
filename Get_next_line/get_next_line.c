/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:49 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/18 20:31:28 by noelsanc         ###   ########.fr       */
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
	line = ft_calloc(sizeof(char) * (i + 2));

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
	new_line = ft_calloc(sizeof(char) * (ft_strlen(stored) - i + 1));
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

	if (!aux)
		return (0);
	aux = ft_strjoin(temp, stored);
	free (stored);
	return (aux);
}

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		*temp_buffer;
	static char	*stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_buffer = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (0);
	read_bytes = 1;
	while (ft_strchr(stored, '\n') && read_bytes > 0)
	{
		temp_buffer[read_bytes] = '\0';
		stored = ft_strjoin(stored, temp_buffer);
		read_bytes = read (fd, temp_buffer, BUFFER_SIZE);
	}
	if (read_bytes < 0)
	{
		free(stored);
		return (NULL);
	}
	line = ft_extract_line(stored, '\n');
	stored = ft_update_stored(stored);
	return (line);
}
