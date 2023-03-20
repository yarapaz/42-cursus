/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:47:03 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:34:49 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int n)
{
	return ((n >= 0 && n <= 127));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("custom %d\n", ft_isascii(48));
	printf("original %d\n", isascii(48));
}*/
