/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:03:59 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:36:24 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dest_aux;
	char			*src_aux;
	size_t			i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	dest_aux = (char *)dest;
	src_aux = (char *)src;
	while (i < n)
	{
		dest_aux[i] = src_aux[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *src;
	void *dest;

	src = "hellou";
	dest = malloc(6 * sizeof(char));
	printf("%s\n", ft_memcpy(dest, src, 2));
	return (0);
}*/
