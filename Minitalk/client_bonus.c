/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:04:19 by noelsanc          #+#    #+#             */
/*   Updated: 2024/10/03 20:46:51 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/minitalk.h"

void	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		printf("Incorrect arguments number\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			printf("Wrong PID! It must be a number.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
void	char_to_bit(int pid, int c)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if((c & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(40);
		i++;
	}
}

void	sig_user(int signal)
{
	if (signal == SIGUSR1)
		printf("RECEIVED\n");
		printf("\U0001F44D\n");
}
int main(int argc, char **argv)
{	
	int pid;
	int i;

	ft_check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &sig_user);
	signal(SIGUSR2, &sig_user);
	i = 0;
	while (argv[2][i] != '\0')
	{
		char_to_bit(pid, argv[2][i]);
		i++;
	}
	char_to_bit(pid, '\0');
	return(0);
}


