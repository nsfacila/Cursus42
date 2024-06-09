/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:25:28 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/09 21:57:49 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 10)
	{
		i = ft_putunsigned(n % 10);
		i = ft_putchar(n % 10 + '0');
	}
	else
		i = ft_putchar(n + '0');
	return (i);
}
