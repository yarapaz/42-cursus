/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:26 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/12 19:16:05 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substring;
	size_t				i;
	size_t				length_s;

	i = 0;
	length_s = ft_strlen((char *)s);
	if (len == 0 || length_s == 0)
		return (ft_strdup(""));
	if (start >= length_s)
		return (ft_strdup(""));
	if (len > length_s - start)
		len = length_s - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
