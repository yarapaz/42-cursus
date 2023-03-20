/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:36 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/09 20:52:53 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
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
