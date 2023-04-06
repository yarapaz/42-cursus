/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:57:54 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/28 19:58:13 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*result;
	int		i;

	i = 0;
	length = ft_strlen(s1);
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (0);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	length_s;

	if (s == NULL)
		return (NULL);
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

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/* char	*ft_strcut(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (ft_substr(str, i + 1, ft_strlen(str) - i));
		i++;
	}
	return (NULL);
} */

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}


