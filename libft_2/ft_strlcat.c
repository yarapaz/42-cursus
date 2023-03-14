/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:37:16 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/08 12:57:33 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclength;
	size_t	destlength;

	srclength = ft_strlen(src);
	destlength = ft_strlen(dest);
	i = 0;
	j = 0;
	if (dstsize <= destlength)
		return (srclength + dstsize);
	if (dstsize > 0)
	{
		while (dest[i] != '\0')
			i++;
		while ((src[j] != '\0') && (j < dstsize - destlength - 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (destlength + srclength);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src;
	char	*dest;
	unsigned int n;

	dest = "nezukochan";
	src = "tanjiro";
	n = ft_strlcat(dest, src, 10);
	printf("%d", n);
}*/
