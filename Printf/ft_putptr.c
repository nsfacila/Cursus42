/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:48:00 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/09 21:18:14 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long n)
{
	int i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_puthexa(n, "0123456789abcdef");
	return (i);
}
/* Usamos la funcion ft_putptr para imprimir un puntero. Usamos unsigned long long ya que un puntero ptr se convierte a un valor entero sin signo de 64 bits (unsigned long long). Esto es porque una dirección de memoria puede representarse como un entero grande, y unsigned long long es adecuado para almacenar direcciones en sistemas de 64 bits.
La función ft_putptr toma un argumento n que es un puntero y lo imprime en hexadecimal. Primero, se declara una variable i de tipo int y se inicializa en 0. Luego, se incrementa i con el valor de ft_putstr('0x'), que imprime el prefijo '0x' para indicar que el número es hexadecimal. Luego, se incrementa i con el valor de ft_puthexa(n, 0), que imprime el valor hexadecimal del puntero n. Finalmente, se devuelve el valor de i, que es el número total de caracteres impresos.
ft_putstr("0x") llama a la función ft_putstr para imprimir la cadena "0x", que es el prefijo comúnmente usado para indicar que lo que sigue es un número hexadecimal. El numero de cacteres(que es 2) se almacena en la variable i.
ft_puthexa(n, 0) llama a la función ft_puthexa para imprimir en formato hexadecimal el valor del puntero n. El valor de n se convierte a hexadecimal y se imprime. El número de caracteres impresos se almacena en la variable i.
Finalmente, se devuelve el valor de i, que es el número total de caracteres impresos.
n: Este es el número que queremos convertir a hexadecimal. En nuestro caso, es la dirección de memoria convertida a un entero sin signo de 64 bits (unsigned long long).
0: Se pasa como argumento a ft_puthex para especificar el formato de impresión. Aquí, 0 probablemente indica que queremos usar dígitos hexadecimales en minúsculas.
*/