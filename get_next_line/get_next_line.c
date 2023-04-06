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

static int read_buffer(int fd, char *store_line)
{
	int		bytes;

	bytes = read(fd, store_line, BUFFER_SIZE);
	return (bytes);
}

static char	*manage_end_of_file(char *store_line)
{
	char	*aux_line;
	char	*char_ptr;
	int		char_pos;

	char_pos = 0;
	aux_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux_line)
		return (NULL);
	char_ptr = ft_strchr(store_line, '\n');
	if (char_ptr == 0)
		return (store_line);
	else
	{
		char_pos = store_line - char_ptr;
		aux_line = ft_substr(store_line, 0, char_pos);
		store_line = ft_substr(store_line, char_pos + 1, ft_strlen(store_line));
		return (aux_line);
	}
	return (NULL);
}
static char	*manage_file(char *store_line, int fd)
{
	char	*aux_line;
	char	*char_ptr;

	aux_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux_line)
		return (NULL);
	char_ptr = ft_strchr(store_line, '\n');
	while (char_ptr == 0)
	{
		read_buffer(fd, aux_line);
		store_line = ft_strcat(store_line, aux_line);
		char_ptr = ft_strchr(store_line, '\n');
	}
	return (store_line);
}

static char *reading_conditions(int bytes, char *store_line, int fd) 
{
	if (bytes == 0 && store_line != NULL)
		return (manage_end_of_file(store_line));
	else if (bytes <= 0)
		return (NULL);
	if (bytes != BUFFER_SIZE)
		return (manage_end_of_file(store_line));
	else if (bytes == BUFFER_SIZE)
		return (manage_file(store_line, fd)); 
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*store_line;
	char *char_ptr;
	int		char_pos;

	int	bytes;

	bytes = 0;
	if (!store_line)
	{
		store_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!store_line)
			return (NULL);
	}
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	else if (fd != -1 && BUFFER_SIZE > 0)
	{
		bytes = read_buffer(fd, store_line);
		store_line = reading_conditions(bytes, store_line, fd);
		char_ptr = ft_strchr(store_line, '\n');
		char_pos = char_ptr - store_line;
		store_line = ft_substr(store_line, char_pos + 1, ft_strlen(store_line));
		return (ft_substr(store_line, 0, char_pos)); //devuelve los reminders, no las lineas
	}	
	return (NULL);
}

