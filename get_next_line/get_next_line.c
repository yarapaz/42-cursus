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
/* 
static int read_buffer(int fd, char *store_line)
{
	int		bytes;
	char 	*new_line;

	new_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!new_line)
		return (0);
	bytes = read(fd, new_line, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(new_line);
		return (0);
	}
	store_line = ft_strjoin(store_line, new_line);
	return (bytes);
}

static int	search_line(char *store_line)
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

static char *manage_reading_end_of_file(char *store_line) 
{
	int	char_pos;
	char *new_line;

	char_pos = 0;
	char_pos = search_line(store_line);
	if ((size_t)char_pos == ft_strlen(store_line))
	{
		new_line = ft_substr(store_line, 0, char_pos);
		free(new_line);
		return (new_line);
	}
	else
	{
		new_line = ft_substr(store_line, 0, char_pos);
		store_line = ft_substr(store_line, (char_pos + 1), ft_strlen(store_line) - 1);
		return (new_line);
	}
	return (NULL);
} 


static char *manage_reading_file(char *store_line) 
{
	int	char_pos;
	int	bytes_read;
	char *new_line;

	char_pos = 0;
	bytes_read = 0;
	char_pos = search_line(store_line);
	while ((size_t)char_pos == ft_strlen(store_line))
	{
		bytes_read = search_line(store_line);
		char_pos = search_line(store_line);
		if (bytes_read == 0 && ((size_t)char_pos == ft_strlen(store_line)))
		{
			new_line = ft_substr(store_line, 0, char_pos);
			free(new_line);
			store_line = NULL;
			return (new_line);
		}
	}
	new_line = ft_substr(store_line, 0, char_pos);
	store_line = ft_substr(store_line, (char_pos + 1), ft_strlen(store_line) - 1);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*store_line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 || fd == -1) 
		return (NULL);
	if (!store_line)
	{
		store_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	}
	bytes_read = read_buffer(fd, store_line);
	if (bytes_read == 0 && ft_strlen(store_line) == 0)
	{
		store_line = NULL;
		free(store_line);
		return (NULL);
	}
	else if (bytes_read == 0 && ft_strlen(store_line) != 0) 
		return (manage_reading_end_of_file(store_line));
	else if (bytes_read > 0)
		return (manage_reading_file(store_line));
	return (NULL);
} */
//NEW GNL

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t			i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (0);
	while (i < count * size)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}

char	*read_file(int fd, char *store_line)
{
	char 	*new_line;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		new_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!new_line)
			return (NULL);
		bytes_read = read(fd, new_line, BUFFER_SIZE); 
		if (bytes_read == -1)
		{
			free(new_line);
			return (NULL);
		}
		store_line = ft_strjoin(store_line, new_line);
		free(new_line);
		if (ft_strchr(store_line, '\n') != 0)
			break ;
	}
	return (store_line);
}

char	*ft_line(char *store_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!store_line || store_line[0] == '\0')
		return (NULL);
	while (store_line[i] && store_line[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char)); 
	if (!line)
		return (NULL);
	i = 0; 
	while (store_line[i] && store_line[i] != '\n')
	{
		line[i] = store_line[i];
		i++;
	}
	if (store_line[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store_line;
/* 	char		*aux_line; */
	char		*line;
	char		*char_ptr;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 || fd == -1) 
		return (NULL);
	if (!store_line)
	{
		store_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!store_line)
			return (NULL);
	}
	store_line = read_file(fd, store_line);
	char_ptr = ft_strchr(store_line, '\n');
	if (char_ptr == NULL)
	{
		line = ft_strdup(store_line);
		free(store_line);
		store_line = ft_strdup("");
	}
	else
	{
		line = ft_substr(store_line, 0, char_ptr - store_line);
		store_line = ft_substr(store_line, char_ptr - store_line + 1, 
			ft_strlen(store_line) - (char_ptr - store_line +1));
		/*aux_line = ft_remain(store_line, line);
		free(store_line);
		store_line = ft_strdup(aux_line);
		free(aux_line);*/
	}
	return (line);		
}
