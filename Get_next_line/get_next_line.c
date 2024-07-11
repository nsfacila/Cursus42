/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:49 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/11 17:14:42 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ssize_t read(int fd, void *buffer, size_t nbyte)
#include <unistd.h>

void	putchar_test_file(char c)
{
	int	fd;

	if (fd > 0)
		write(1, &c, 1);
	else
		write(2, "prueba.txt not found.\n", 23);
}
int main
*/

static char	*extract_line(char *stored)
{
	char	*line;
	int		i;

	if (!*stored)
		return (0);
	i = 0;
	while (stored[i] != '\n' && stored[i] != 0)
		i++;
	line = malloc (sizeof(char) * (i + 2));
	if (*line != 0)
		return (0);
	i = 0;
	while (stored[i] != '\n')
	{
		line[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
		*line = '\n';
	line[i + 1] = '\0';
	return (line);
}

static char	*ft_update_stored (char *stored)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while(stored[i] != '\n' && stored[i] != 0)
		i++;
	if (!stored)
		return (0);
	new_line = malloc(sizeof(char) * (ft_strlen(stored) - i + 1));
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
static char	*read_to_store(fd, char *stored)
{
	char	*buffer;
	int	read_bytes;
	
	read_bytes = read(fd, stored, BUFFER_SIZE)
}
