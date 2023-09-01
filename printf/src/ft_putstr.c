/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:13:20 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/01 18:45:43 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int counter;
	int	i;

	counter = 0;
	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		counter += ft_putchar(s[i]);
		i++;
	}

	return (counter);
}
