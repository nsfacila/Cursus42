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

void 	char_to_bit(int pid, int c)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;

		usleep(100);
	}
}

void	send_str(int pid, char *s)
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
void	sig_user(int signal)
{
	int bit_control;

	if (signal == SIGUSR1)
		bit_control = 1;
	else
	{
		ft_printf("RECEIVED\n");
		exit(EXIT_SUCCESS);
	}
}
int main(int argc, char **argv)
{	
	int pid;

	if (argc != 3)
	{
		ft_printf("incorrect arguments number\n");
		return(1);
	}
	signal(SIGUSR1, &sig_user);
	signal(SIGUSR2, &sig_user);

	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);

	while(1)
		sleep(1);
	return(0);
}