/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:50:41 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/12 17:48:37 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*insertdigits(int n, char *finalstring, int numdigits)
{
	int	i;

	i = 0;
	if (n == 0)
		finalstring[i] = '0';
	else if (n < 0)
	{
		finalstring[i] = '-';
		n = -n;
		i++;
	}
	i = numdigits + 1;
	while (n > 0)
	{
		finalstring[i - 2] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	finalstring[numdigits] = '\0';
	return (finalstring);
}

static	int	getnumofdigits(int n)
{
	int	numofdigits;

	numofdigits = 0;
	if (n <= 0)
	{
		numofdigits++;
		n = -n;
	}
	while (n > 0)
	{
		numofdigits++;
		n = n / 10;
	}
	return (numofdigits);
}

char	*ft_itoa(int n)
{
	char	*finalstring;
	int		numdigits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	numdigits = getnumofdigits(n);
	finalstring = (char *)malloc((numdigits + 1) * sizeof(char));
	if (!finalstring)
		return (0);
	finalstring = insertdigits(n, finalstring, numdigits);
	return (finalstring);
}
/*
int	main(void)
{
	printf("custom %s\n", ft_itoa(0));
	printf("custom %s\n", ft_itoa(4));
	printf("custom %s\n", ft_itoa(45));
	printf("custom %s\n", ft_itoa(-145));
	printf("custom %s\n", ft_itoa(-2147483648));
	return (0);
}*/
