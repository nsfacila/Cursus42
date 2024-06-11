/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:48:14 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/03 21:06:13 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}
/*Se declara una variable tipo int llamada i y se le asigna el valor de 0 para inicializarla. Esta variable se usa para almacenar el valor de i y que cuente el número de caracteres que se imprimen en la función ft_putchar. Se crea un bucle while que se ejecutará mientras el puntero s no sea igual a '\0'. Dentro del bucle se incrementa el valor de i con el valor de la función ft_putchar, devolviendo el numero de caracteres que imprima. Se incrementa el puntero s para avanzar en la string.
Variable i: Se utiliza para llevar la cuenta de cuántos caracteres se han impreso. Cada vez que se imprime un carácter, se incrementa i en 1.*/