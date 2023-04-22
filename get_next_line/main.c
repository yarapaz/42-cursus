/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:34:15 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/29 17:34:20 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int	fd;
	char	*aux_line;

	fd = open("file.txt", O_RDONLY);
	aux_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while ((aux_line = get_next_line(fd)) != NULL)
	{
		printf("line:%s \n", aux_line);
	};
	system("leaks main");
	return (0);
}
