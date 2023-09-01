/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:18 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/01 18:54:41 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexa(unsigned int n, char *base)
{
	int		counter;
	int		positions[50];
	int		i;

	counter = 0;
	i = 0;
	if (n == 0)
		counter += ft_putchar('0');
	while (n > 0)
	{
		positions[i] = n % 16;
		n = n / 16;
		i++;
	}
	while (--i >= 0)
		counter += ft_putchar(base[positions[i]]);
	return (counter);
}
