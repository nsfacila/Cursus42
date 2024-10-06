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


void siguser_handler(int signal, siginfo_t *info, void *context)
{
    static int bit = 0; // Mantener el contador de bits
    static unsigned char byte = 0; // Almacena el byte recibido

    (void)context;
    if (signal == SIGUSR1)
    {
        byte |= (1 << bit); // Acumula el bit
    }
    
    bit++; // Incrementa el contador de bits

    if (bit == 8) // Si se han recibido 8 bits
    {
        if (byte == '\0') // Fin del mensaje
        {
            printf("\n"); // Imprime una nueva línea
            kill(info->si_pid, SIGUSR1); // Envía confirmación al cliente
        }
        else
        {
            printf("%c", byte); // Imprime el byte
        }
        // Reinicia las variables
        bit = 0;
        byte = 0;
    }
}


int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = signal_handler; // Estableces la función que manejará las señales.
	sa.sa_flags = SA_SIGINFO; // Pides recibir información extra sobre la señal.
	sigaction(SIGUSR1, &sa, NULL); // Configuras que cuando llegue SIGUSR1, se use 'signal_handler'.
	sigaction(SIGUSR2, &sa, NULL); // Lo mismo para SIGUSR2.
	printf("Servidor: Obteniendo ID de proceso %d\n", getpid());
	while (1)
		pause(); // Esperar una señal para ejecutar el handler
	return (0);
}
// sigaction es una estructura que se utiliza para definir cómo un programa manejará una señal específica. 
/* sa.sa_sigaction:
Aquí asignas la función que va a manejar la señal. En tu caso, es signal_handler.
sa.sa_flags:
Configura opciones adicionales sobre cómo se maneja la señal.
SA_SIGINFO indica que queremos recibir información extra en nuestra función de manejo de señales, */
