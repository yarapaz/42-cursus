/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:13:20 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/05 18:05:31 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	counter;
	int	i;

	counter = 0;
	if (s == NULL)
	{
		counter += ft_putstr("(null)");
		return (counter);
	}
	i = 0;
	while (s[i] != '\0')
	{
		counter += ft_putchar(s[i]);
		i++;
	}
	return (counter);
}
