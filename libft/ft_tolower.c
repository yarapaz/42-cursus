/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:59:03 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/08 21:36:22 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 97 && c <= 122)
		return (c);
	else if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c;
	c = '*';
	printf("%c\n", ft_tolower(c));
}*/
