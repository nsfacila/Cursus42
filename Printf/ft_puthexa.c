/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:51:52 by noelsanc          #+#    #+#             */
/*   Updated: 2024/06/09 20:44:17 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexa(unsigned int nb, char *base)
{
	char	i;

	i = 0;

	if (nb < 16)
	{
		i = base[nb];
		ft_putchar(i);
	}
	if(nb >= 16)
	{
		i = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	result (i);
}
int main()