/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:45:16 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:36:36 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	void	*src = "charmander";
	void	*dst = "pikachu";

	printf("custom %s\n", ft_memmove(dst, src, 5));
	printf("original %s\n", memmove(dst, src, 5));
}*/
