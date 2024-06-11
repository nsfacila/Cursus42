/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:51:52 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/11 22:43:11 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long int nb, char *base)
{
	int		i;

	i = 0;
	if (nb < 16)
	{
		i += ft_putchar(base[nb]);
	}
	else
	{
		i += ft_puthexa(nb / 16, base);
		i += ft_putchar(base[nb % 16]);
	}
	return (i);
}
/*
int main()
{
	char base[16] = "0123456789abcdef";
	int nb = 42;
	ft_puthexa(nb, base);
	return 0;
}
La función ft_puthexa toma dos argumentos: un número entero sin signo nb y una cadena de caracteres base que contiene los dígitos hexadecimales. La función imprime el número nb en formato hexadecimal utilizando los dígitos hexadecimales de la cadena base.
*/
