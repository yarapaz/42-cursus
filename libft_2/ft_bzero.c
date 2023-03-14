/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:41:51 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/08 20:44:45 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	char			*aux;

	aux = (char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	return (0);	
}*/
