/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:59:31 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:35:48 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*aux;

	aux = (char *)b;
	i = 0;
	while (i < len)
	{
		aux[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	void	*b;


	b = malloc(5 * sizeof(char));
	printf("custom %s\n", ft_memset(b, 'a', 5));
	printf("original %s\n", memset(b, 'a', 5));
}*/
