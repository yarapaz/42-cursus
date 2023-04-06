/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:15:02 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/26 18:15:07 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strcat(char *dest, const char *src);
size_t	ft_strlen(const char *str);
char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif