/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:41:51 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:36:02 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
