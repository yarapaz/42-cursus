/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:11:02 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/27 15:49:43 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>



static char *read_buffer(int fd, char *store_line)
{
	int		bytes;
	char 	*new_line;

	new_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	bytes = read(fd, new_line, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(new_line);
		return (NULL);
	}
	store_line = ft_strjoin(store_line, new_line);
	//meter aqui la funcion search_line para controlar el numero de bytes leidos
	return (store_line);
}

static int	search_end_of_line(char *store_line)
{
	char	*char_ptr;
	int		char_pos;

    char_ptr = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!char_ptr)
		return (0);
	char_ptr = ft_strchr(store_line, '\n');
	if (char_ptr != 0)
	{
		char_pos = char_ptr - store_line;
		free(char_ptr);
		return (char_pos);
	}
	free(char_ptr);
	return (ft_strlen(store_line) - 1);
}

char	*get_next_line(int fd)
{
	static char	*store_line;
	char		*new_line;
	int			char_pos;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 || fd == -1) 
		return (NULL);
	if (!store_line)
	{
		store_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!store_line)
			return (NULL);
	}
	store_line = read_buffer(fd, store_line);
	if (ft_strlen(store_line) != 0)
	{
		char_pos = search_end_of_line(store_line); 
		while ((size_t)char_pos == (ft_strlen(store_line) - 1)) 
		{
			store_line = read_buffer(fd, store_line);
			if (char_pos == 0 || )
				return (store_line);
			char_pos = search_end_of_line(store_line);
		}
		new_line = ft_substr(store_line, 0, char_pos);
		store_line = ft_substr(store_line, (char_pos + 1), ft_strlen(store_line) - 1);
		return (new_line);
	}
	store_line = ft_strdup("");
	free(new_line);
	free(store_line);
	return (NULL);
}
