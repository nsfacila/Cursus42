/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:50:40 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/21 22:56:00 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42

# endif

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t size, size_t count);
char	*ft_join_free(char *temp, char *stored);
char	*ft_update_stored(char *stored);
char	*ft_extract_line(char *stored);
char	*get_next_line(int fd);

#endif