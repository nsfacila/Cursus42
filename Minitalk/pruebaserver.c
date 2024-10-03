#include "./include/minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum)
{
	if(signum == SIGUSR1)
		printf("recibi signal SIGUSR1\n");
	else if(signum == SIGUSR2)
		printf("recibi signal SIGUSR2\n");
}

int main()
{
	pid_t getpid(void); 
	//registra los manejadores de señales
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	//obtener el PID del programa llamar a la funcion getpid
	printf("servidor: obteniendo ID del proceso %d\n", getpid());

	while(1) //bucle infinito para esperar señales
	{
		printf("servidor: esperando señales\n");
		pause();
	}
	return(0);
}

//Mis señales son SIGUSR1 y SIGUSR2
/* signal(SIGUSR1, manejador_senal): Esto registra un "manejador" para la señal SIGUSR1. Cuando el servidor recibe esta señal, ejecuta la función manejador_senal.

manejador_senal(int signo): Es la función que se ejecuta cuando se recibe una señal. Verifica qué señal fue recibida (SIGUSR1 o SIGUSR2) e imprime el mensaje correspondiente.

getpid(): Esto imprime el PID (identificador de proceso) del servidor, que el cliente necesitará para enviarle las señales.

pause(): Esta función pone al servidor en pausa, esperando a que llegue una señal. Una vez que una señal es recibida y el manejador se ejecuta, vuelve a pausar el programa para seguir esperando más señales. */