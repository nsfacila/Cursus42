/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:04:08 by noelsanc          #+#    #+#             */
/*   Updated: 2024/10/03 19:57:40 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int ft_atoi(char *str)
{
	int sign;
	int result;
	int i;
	
	sign = 1;
	result = 0;
	i = 0;
	
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return(result * sign);
}
/* int main(void)
{
	char s[] = "  -123";
	int res = ft_atoi(s);
	printf("%d\n", res);
	return(0);
} */