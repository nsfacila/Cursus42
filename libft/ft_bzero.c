/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:52:09 by noelsanc          #+#    #+#             */
/*   Updated: 2024/05/22 22:41:48 by noelsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int main()
{
	char str[] ="Diplodocus";
	ft_bzero(str, 4);
	for(int i = 0; i < 9; i++)
	{
		printf("%c ", str[i]);
	}
}*/
