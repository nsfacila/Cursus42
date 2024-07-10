/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:49 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/27 19:01:03 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ssize_t read(int fd, void *buffer, size_t nbyte)
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