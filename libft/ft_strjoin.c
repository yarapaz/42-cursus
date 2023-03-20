/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:43:27 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/10 18:09:35 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	loop(char *s1, char *s2, char *newstring)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstring[i] = s2[j];
		i++;
		j++;
	}
	newstring[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!newstring)
		return (0);
	loop((char *)s1, (char *)s2, newstring);
	return (newstring);
}
