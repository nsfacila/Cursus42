/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:07:00 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/11 20:37:44 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
/*
int main()
{
	int	nums = -123;
	{
		ft_putnbr(nums);
		write(1, "\n", 1);
	return (0);
	}
}
*/