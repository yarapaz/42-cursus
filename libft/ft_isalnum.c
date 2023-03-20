/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:36:21 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/17 16:34:44 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int n)
{
	return (ft_isalpha(n) || ft_isdigit(n));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("custom %d\n", ft_isalnum(1));
	printf("original %d\n", isalnum(1));
}*/
