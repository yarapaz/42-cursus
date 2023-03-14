/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:11:19 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/08 11:08:00 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char	*str;
	str = "42";
	printf("custom: %lu\n", ft_strlen(str));
	printf("original %lu\n", strlen(str));
}*/
