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

static char *lower_bytes(int bytes, char *aux_line, char *line, char *file)
{
	if (!aux_line)
	{
		line = ft_substr(file, 0, bytes);
		free(file);
		return (line);
	}
	else 
	{
		return (ft_strcat(aux_line, ft_substr(file, 0, bytes)));
	}
	return (NULL);
}

static char *same_bytes(char *aux_line, char *line, char *file, int bytes)
{
	int			i;

	i = 0;
	if (aux_line)
		line = ft_strcat(aux_line, ft_substr(file, 0, bytes));
	else
		line = ft_substr(file, 0, bytes);
	free(file);
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && line[i + 1] == '\0')
			return (line);
		else if (line[i] == '\n' && line[i + 1] != '\0')
		{
			aux_line = ft_strcut(line, '\n');
			line = ft_substr(line, 0, i);
			return (line);	
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*aux_line;
    char		*file;
	char		*line;
	int			bytes;
	int			i;
	int			j;

	i = 0;
	j = 0;
	bytes = 0;
    if (fd != -1)
    {
		file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!file)
			return (NULL);
		bytes = read(fd, file, BUFFER_SIZE);
		if (bytes == 0 || bytes < 0)
			return (NULL);
		if (bytes != BUFFER_SIZE)
			lower_bytes(bytes, aux_line, line, file);
		else if (bytes == BUFFER_SIZE)
		{
			same_bytes(bytes, aux_line, line, file);
			get_next_line(fd);
		}
	}
	return (NULL);
}
