/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:56:16 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/13 19:40:23 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*finalstring;

	i = 0;
	finalstring = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!finalstring)
		return (0);
	while (s[i] != '\0')
	{
		finalstring[i] = (*f)(i, s[i]);
		i++;
	}
	finalstring[i] = '\0';
	return (finalstring);
}
