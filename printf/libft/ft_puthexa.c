/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:18 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/13 20:57:52 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_puthexa(int n, char *base)
{
	int	counter;

//recibo el numero
//recibo la base
	if (n == 0)
		counter += ft_putchar((n + '0'));
	if (n <= 9)
		counter += ft_putchar((n + '0'))
	if (n > 0)
	{
		if (n <= 9)
			counter += ft_putchar((n + '0'));
		else if (n > 9)
		{
			ft_putnbr(n / 10);
			counter += ft_putchar(((n % 10) + '0'));
		}
	}
	return (counter);
}
