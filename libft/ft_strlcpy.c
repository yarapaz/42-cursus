/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:19:45 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/09 20:55:31 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclength;

	i = 0;
	srclength = 0;
	while (src[srclength] != '\0')
		srclength++;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclength);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "pikachu";
	char dest[] = "charmander";
	int i;

	i = ft_strlcpy(dest, src, 10);
	printf("%d:%s", i, dest);
}*/
