/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:32:23 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:34:38 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int n)
{
	return ((n >= '0' && n <= '9'));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("custom %d\n", ft_isdigit(48));
	printf("original %d\n", isdigit(48));
}*/
