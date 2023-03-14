/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:49:12 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/13 18:35:13 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	i = 0;
	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i + 1 < n) && (aux_s1[i] == aux_s2[i]))
		i++;
	return (aux_s1[i] - aux_s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "555abc";
 	char *s2 = "iiiiabj";
 	size_t size = 4;

 	printf("original: %d\n", memcmp(s1, s2, size));
 	printf("custom: %d\n", ft_memcmp(s1, s2, size));
}*/
