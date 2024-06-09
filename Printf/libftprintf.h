/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:40:04 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/05 16:46:33 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
void ft_putnbr(int n);
int ft_printf_prueba(char *str, ...);

#endif