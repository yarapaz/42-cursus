/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:29:22 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/12 20:27:29 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	result;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i + ft_strlen(needle) <= len))
	{
		result = ft_strncmp(&haystack[i], needle, ft_strlen(needle));
		if (result == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char *haystack = "see FF your FF return FF now FF";
	const char *needle = "FF";
	printf("custom: %s\n", ft_strnstr(haystack, needle, 4));
	printf("original: %s\n", strnstr(haystack, needle, 4));
}*/
