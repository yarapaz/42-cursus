/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:30:08 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/20 20:15:53 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_start_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!ft_strchr(set, (int)s1[i]))
			return (i);
		i++;
	}
	return (0);
}

static int	get_end_index(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	if (i == -1)
		i = 0;
	while (s1[i] != '\0')
	{
		if (!ft_strchr(set, ((int)s1[i])))
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_index = get_start_index(s1, set);
	end_index = get_end_index(s1, set);
	if (end_index == 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start_index, ((end_index - start_index) + 1)));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("custom: %s\n", ft_strtrim("", ""));
	return (0);
}*/
