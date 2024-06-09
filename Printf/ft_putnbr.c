/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:07:00 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/05 17:29:24 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		n = '-';
		write (1, "-2147483648", 11 );
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		n = n + '0';
	ft_putchar(n);
}

int main()
{
	int	nums = -123;
	{
		ft_putnbr(nums);
		write(1, "\n", 1);
	return (0);
	}
}
