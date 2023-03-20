/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:56:13 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:35:04 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int n)
{
	return ((n >= 32 && n <= 126));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("custom %d\n", ft_isprint(40));
	printf("original %d\n", isprint(40));
}*/
