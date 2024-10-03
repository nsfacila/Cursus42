/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:04:39 by noelsanc          #+#    #+#             */
/*   Updated: 2024/10/03 20:51:18 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"
#include "ft_printf.h"

// Para la funcion signaction ,
	//necesitamos un prototipo con tres variables para tener mas info sobre la señal recibida
// La señal que recibimos,
	//informacion acerca de la señal en este caso nos interesa el ID del proceso de la señal que envia el cliente y context aqui no se utiliza

static void	siguser_handler(int signal, siginfo_t *info, void *context)
{
	static int nb;  // almacena cada binario para formar nuestro caracter
	static int bit; // el iterador que recorre los bits;
	nb = 0;
	bit = 7;
	(void)context;
	if (signal == SIGUSR1)
		nb += 1 << bit; //'a' = 97 01100001 ,
			movemos 7 posiciones y nos quedamos con el caracter mas a la izq ,
			el 0 lo salta el 1 lo almacena , y movemos posicion con iterador
	bit--;             
		// cuando termina de almacenar los 8 bits para formar el caracter i será
		-1 ya que decrementa 1 al final.
	if (bit == -1)     
		// cuando el iterador haya almacenado los 8 bits print el caracter
	{
		if (nb == '\0')
			ft_printf("\n");
		else
			ft_printf("%d", nb);
		nb = 0;
			// IMPORTANTE reiniciar numero y el iterador para pasar al segundo caracter del texto
		bit = 7;
	}
	kill(info->si_pid, SIGUSR1);
		// la señal se ejecuta de esta manera ya que almacena mas informacion,
		el pid del cliente que envia la señal
}
int	main(void)
{
	struct sigaction sa; // Para definir la estructura de sigaction es necesario
	sa.sa_sigaction = siguser_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Servidor:Obteniendo ID de prceso\n", getpid());
	while (1)
	{
		// pause();
	}
	return (0);
}
