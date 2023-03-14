/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:54:55 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/08 20:27:50 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i + 1 < size)
		&& (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char	*s1 = "test\200";
	char	*s2 = "test\0";
	int	result;

	result = ft_strncmp(s1, s2, 6);
	printf("custom %d\n", result);
	printf("original %d\n", strncmp(s1, s2, 6));
}*/
