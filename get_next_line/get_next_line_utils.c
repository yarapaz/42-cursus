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
	if (str == NULL)
		return (0);
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
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
		return (NULL);
	if (start >= length_s)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2 && s1)
		return ((char *)s1);
	if (!s1)
		return (NULL); 
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	while (s1[++i] != '\0')
		newstring[i] = s1[i];
	while (s2[j] != '\0')
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	free(s1);
	return (newstring);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return(0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

