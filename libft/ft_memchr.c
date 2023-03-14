/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:25:56 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/09 16:38:35 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*aux_s;

	i = 0;
	aux_s = (unsigned char *)s;
	while (i < n)
	{
		if (aux_s[i] == (unsigned char)c)
			return ((void *)&aux_s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5}; 
	printf("custom %p\n", ft_memchr(s, 2 + 256, 3));
	printf("original %p\n", memchr(s, 2 + 256, 3));
}*/
