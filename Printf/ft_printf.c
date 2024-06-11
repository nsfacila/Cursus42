/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:34:52 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/11 22:09:24 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, va_list argu)
{
	int	count;

	count = 0;
	if (*format == '%')
		count += ft_putchar('%');
	else if (*format == 'c')
		count += ft_putchar(va_arg(argu, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(argu, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(argu, int));
	else if (*format == 'u')
		count += ft_putunsigned(va_arg(argu, unsigned int));
	else if (*format == 'x')
		count += ft_puthexa(va_arg(argu, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		count += ft_puthexa(va_arg(argu, unsigned int), "0123456789ABCDEF");
	else if (*format == 'p')
		count += ft_putptr(va_arg(argu, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_check_format(str, args);
			str++;
		}
		else
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	num;

	num = ft_printf("Tengo que imprimir esta frase sin porcentajes\n");
	printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
	num = ft_printf("Tengo que imprimir la frase mayúscula y es %s\n", 'HOLA');
	printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
	return (0);
}


int main()
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf("Integer: %d\n", 42);
	ft_printf("Pointer: %p\n", main);
	ft_printf("Hex (lowercase): %x\n", 255);
	ft_printf("Hex (uppercase): %X\n", 255);
	return 0;
}
*/