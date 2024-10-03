/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:04:30 by noelsanc          #+#    #+#             */
/*   Updated: 2024/10/03 20:33:28 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

void	char_to_bit(int pid, int c)
{
	int bit;

	bit = 7;

	
	while (bit >= 0)
	{
		if ((c >> bit) & 1) //El operador >> desplaza los bits del carácter hacia la derecha. Así, podemos analizar cada bit de manera individual.
			kill(pid, SIGUSR1); // enviamos SigusR1 que representa '1' bit.
		else
			kill(pid, SIGUSR2); // enviamos SIgusR2 que representa  '0' bit.
		bit--;

		usleep(200);
	}
}
void send_str(int pid, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		char_to_bit(pid, s[i]);
		i++;
	}
	char_to_bit(pid, '\0');
}
int main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("numero argumentos erroneos\n");
		return(1);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}

	/*Revisar los bits: Supongamos que queremos enviar la letra 'A'. En binario, 'A' es 01000001. La función chat_to_bit() recorre cada uno de estos 8 bits, de izquierda a derecha (desde el bit más significativo).

Desplazar bits (>>):

El operador >> desplaza los bits del carácter hacia la derecha. Así, podemos analizar cada bit de manera individual.
Por ejemplo, si c es 'A' (01000001 en binario), al desplazar 7 veces hacia la derecha (c >> 7), obtenemos el primer bit (que es 0).
Comprobar el bit (& 1):

Una vez que hemos desplazado los bits, hacemos una operación & 1 para obtener el valor del bit más a la derecha (0 o 1). Dependiendo del valor, enviamos SIGUSR1 o SIGUSR2.
	*/