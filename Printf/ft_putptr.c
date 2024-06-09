/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:48:00 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/09 21:18:14 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(unsigned long long n)
{
	int	i;

	i = 0;
	i += ft_putstr('0x');
	i += ft_puthexa(n, '0x');
	return (i);
}
