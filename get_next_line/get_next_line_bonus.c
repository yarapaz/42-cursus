/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:11:02 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/04/27 20:22:22 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_file(int fd, char *store_line)
{
	char	*new_line;
	int		bytes_read;

	bytes_read = 1;
	new_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	while (!ft_strchr(store_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, new_line, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(new_line);
			return (NULL);
		}
		new_line[bytes_read] = '\0';
		store_line = ft_strjoin(store_line, new_line);
	}
	free(new_line);
	return (store_line);
}

char	*ft_line(char *store_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!store_line || store_line[0] == '\0')
		return (NULL);
	while (store_line[i] != '\0' && store_line[i] != '\n')
		i++;
	if (store_line[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (store_line[i] != '\n' && store_line[i] != '\0')
	{
		line[i] = store_line[i];
		i++;
	}
	if (store_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_remain(char *store_line)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	while (store_line[i] != '\n' && store_line[i] != '\0')
		i++;
	if (!store_line[i])
	{
		free(store_line);
		return (NULL);
	}
	remain = ft_calloc((ft_strlen(store_line) - i + 1), sizeof(char));
	if (!remain)
		return (NULL);
	i++;
	j = 0;
	while (store_line[i] != '\0')
		remain[j++] = store_line[i++];
	remain[j] = '\0';
	free(store_line);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*store_line[5000];
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || fd < 0)
	{
		free(store_line[fd]);
		store_line[fd] = NULL;
		return (NULL);
	}
	if (!store_line[fd])
	{
		store_line[fd] = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!store_line[fd])
			return (NULL);
	}
	store_line[fd] = read_file(fd, store_line[fd]);
	if (!store_line[fd])
		return (NULL);
	line = ft_line(store_line[fd]);
	store_line[fd] = ft_remain(store_line[fd]);
	return (line);
}
