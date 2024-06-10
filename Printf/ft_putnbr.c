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
	int	i;

	i = 0;

	if (n == -2147483648)
	{
		i += ft_putstr("-2147483648");
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
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
