/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:49:10 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/05 18:47:17 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_type(char *type, va_list args)
{
	int	counter;

	counter = 0;
	if (*type == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (*type == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (*type == 'p')
	{
		write(1, "0x", 2);
		counter += 2;
		counter += ft_hexpoint(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (*type == 'd' || *type == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (*type == 'u')
		counter += ft_unputnbr(va_arg(args, unsigned int));
	else if (*type == 'x')
		counter += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*type == 'X')
		counter += ft_hexamax(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*type == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(char const *type, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, type);
	while (*type)
	{
		if (*type == '%')
		{
			++type;
			counter += ft_type((char *)type, args);
		}
		else
			counter += ft_putchar(*type);
		++type;
	}
	va_end(args);
	return (counter);
}
