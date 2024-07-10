/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:50:40 by noelsanc          #+#    #+#             */
/*   Updated: 2024/07/02 17:59:38 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>

char	*ft_strchr(const char *s, int c);

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif

#endif