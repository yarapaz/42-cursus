/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:21:30 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/16 18:58:45 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	strchr_pos(char const *s, char c)
{
	char	*ptr;
	int		pos_c;

	ptr = ft_strchr(s, (int)c);
	if (ptr == 0)
		pos_c = ft_strlen(s);
	else
		pos_c = ptr - s;
	return (pos_c);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && (s[i] != c))
			words++;
		i++;
	}
	return (words);
}

static char	**complete_array(char const *s, char c, char **main_string)
{
	int	pos_c;
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if ((*s == c) && (*s))
			s++;
		else if (*s != c)
		{
			pos_c = strchr_pos(s, c);
			if (pos_c)
			{	
				main_string[i] = ft_substr(s, 0, pos_c);
				if (!main_string[i])
					return (NULL);
				i++;
				s += pos_c;
			}
			else
				s++;
		}
	}
	main_string[i] = NULL;
	return (main_string);
}

char	**ft_split(char const *s, char c)
{
	char	**main_string;

	main_string = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!main_string)
		return (NULL);
	main_string = complete_array(s, c, main_string);
	return (main_string);
}
/*
#include <stdio.h>

void print_table(char **table)
{
	int i = 0;

	while (table[i])
	{
		printf("%i:%s\n",i, table[i]);
		i++;
	}
}

int main(void)
{
	char	*s;

	s = " hi hola hellou";
	print_table(ft_split(s, ' '));
	s = "hi hola  hellou ";
	print_table(ft_split(s, ' '));
	s = "   ";
	print_table(ft_split(s, ' '));
	s = "lorem ipsum dolor sit amet, consectetur adipiscing elit";
	print_table(ft_split(s, ' '));
	s = "lorem ipsum dolor sit amet, consectetur adipiscing elit";
	print_table(ft_split(s, ' '));
	return (0);
}*/
