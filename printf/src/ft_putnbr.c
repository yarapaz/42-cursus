/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:18 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/05 18:01:58 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		counter += ft_putchar((n + '0'));
	else if (n == -2147483648)
		counter += ft_putstr("-2147483648");
	else if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(n * -1);
	}
	else if (n > 0)
	{
		if (n <= 9)
			counter += ft_putchar((n + '0'));
		else if (n > 9)
		{
			counter += ft_putnbr(n / 10);
			counter += ft_putchar(((n % 10) + '0'));
		}
	}
	return (counter);
}
