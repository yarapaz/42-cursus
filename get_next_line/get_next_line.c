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
	char 	*aux_line;

	aux_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux_line)
		return (0);
	bytes = read(fd, aux_line, BUFFER_SIZE);
	store_line = ft_strcat(store_line, aux_line);
	return (bytes);
}

static char *search_line(char *store_line)
{
	char	*char_ptr;
	char 	*eof_ptr;

	char_ptr = ft_strchr(store_line, '\n');
	eof_ptr = ft_strchr(store_line, EOF);
	if (char_ptr == 0 && eof_ptr != 0)
		return (store_line);
	else if (char_ptr == 0 && eof_ptr == 0) //no me encuentra el EOF y nunca sabe cuando terminar. No devuelve nunca el store_line. Bucle infinito
		return (char_ptr);
	else if (char_ptr != 0) 
		return (char_ptr);
	return (NULL);
}
static char	*manage_file(char *store_line, int fd, int bytes)
{
	char	*aux_line;
	char	*char_ptr;

	aux_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux_line)
		return (NULL);
	if (bytes == 0 && store_line != NULL)
		return (search_line(store_line));
	else if (bytes != BUFFER_SIZE) 
		return (search_line(store_line)); 
	else if (bytes == BUFFER_SIZE)
	{
		char_ptr = search_line(store_line);
		while (char_ptr == 0)
		{
			read_buffer(fd, aux_line);
			store_line = ft_strcat(store_line, aux_line);
			char_ptr = search_line(store_line);
		}
		return (char_ptr);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*store_line;
	char 		*aux_line;
	int			bytes;
	char		*char_ptr;

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
		if ((char_ptr = manage_file(store_line, fd, bytes)) - store_line == 0)
			return (char_ptr);
		else {
			aux_line = ft_substr(store_line, 0, (char_ptr - store_line));
			store_line = ft_substr(store_line, ((char_ptr - store_line) + 1), ft_strlen(store_line));
			return (aux_line);	
		}
	}	
	return (NULL);
}
