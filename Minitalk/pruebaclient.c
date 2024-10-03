//esta funcion envia la señal al servidor mediante SERGUSR1 y SERGUSR2, para que el cliente la reciba y la ejecute.
#include "./include/minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

	//Mis señales son SIGUSR1 y SIGUSR2
	int main()
	{
		pid_t pid;
		pid = getpid();
		printf("Introduce pid del servidor");
		scanf("%d", &pid); // Se le pide al usuario que introduzca el id del proceso

		printf("Enviando SUGUSR1 al servidor..../n");
		kill(pid, SIGUSR1); //Envia la señal SIGUSR1 al proceso con el pid del servidor;
		
		sleep(1); //Para dar tiempo a enviar la señal

		printf("Enviando SUGUSR1 al servidor..../n");
		kill(pid, SIGUSR2); // Envia la señal SIGUSR2 al proceso con el id del servidor;

		return(0);
	}