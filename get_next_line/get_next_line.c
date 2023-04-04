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

static char *manage_end_of_file(int bytes, char *aux_line, char *line)
{
	int	i;
	char *prov_line;

	i = 0;
	if (!aux_line)
	{
		line = ft_substr(line, 0, bytes);
		return (line);
	}
	else 
	{
		while (aux_line[i] != '\0')
		{
			if (aux_line[i] == '\n' && aux_line[i + 1] == '\0')
			{
				prov_line = aux_line;
				if (line)
					aux_line = line;
				return (ft_substr(prov_line, 0, i));
			}
			else if (aux_line[i] == '\n' && aux_line[i + 1] != '\0')
			{
				prov_line = aux_line;
				if (line)
					aux_line = ft_strjoin(ft_strcut(prov_line, '\n'), (const char*)line);
				else
					aux_line = ft_strcut(prov_line, '\n');
				return (ft_substr(prov_line, 0, i));
			}
		}
		if (line)
			return (ft_strjoin(aux_line, ft_substr(line, 0, bytes)));
		else
			return (aux_line);
	}
	return (NULL);
}

//Desarrollar y comprobar esta función
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
	char		*line;
	int			bytes;

	bytes = 0;
    if (fd != -1)
    {
		if (BUFFER_SIZE == 0)
			return (NULL);
		line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		bytes = read(fd, line, BUFFER_SIZE);
		//Controlar el read
		if (bytes == 0 && aux_line != NULL)
		{
			line = manage_end_of_file(bytes, aux_line, line);
			return (line);
		}
		if (bytes == 0 || bytes < 0)
			return (NULL);
		if (bytes != BUFFER_SIZE)
		{
			line = manage_end_of_file(bytes, aux_line, line);
			return (line);
		}
		//Desarrollar y comprobar esta función
		else if (bytes == BUFFER_SIZE)
		{
			same_bytes(bytes, aux_line, line, file);
			get_next_line(fd);
		}
	}
	return (NULL);
}
