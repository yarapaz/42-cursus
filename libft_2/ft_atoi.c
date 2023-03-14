/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:43:26 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/08 19:30:11 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	val;

	i = 0;
	sign = 1;
	val = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main (void)
{
	char	*str = "  	-456yh";
	printf("custom: %d\n", ft_atoi(str));
	printf("original %d\n", atoi(str));
}*/
