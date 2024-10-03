/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:04:44 by noelsanc          #+#    #+#             */
/*   Updated: 2024/10/03 20:38:34 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/minitalk.h"
//#include <stdio.h>


void signal_handler(int sign)
{
	static int number = 0;
	static int i = 7;
	char	c;

	if (sign == SIGUSR1)
		number += 1 << i;
	if (sign == SIGUSR2)
		number += 0 << i;
	i--;
	if(i == -1)
	{	
		c = (char)number;
		if(number == '\0')
			ft_printf("\n");
		else
			write(1, &c, 1);	
		//ft_printf("%c", number);
		number = 0;
		i = 7;
	}
}
int main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	ft_printf("servidor: obteniendo ID del proceso %d\n", getpid());

	while(1)
	{
		//pause();
	}
	return(0);
}
