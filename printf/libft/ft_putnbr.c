/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:18 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/13 20:57:52 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr(int n)
{
	int	counter;

	if (n == 0)
		counter += ft_putchar((n + '0'));
	if (n == -2147483648)
		counter += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
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
