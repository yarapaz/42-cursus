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

	fd = open("file.txt", O_RDONLY);
	printf("first line:%s \n", get_next_line(fd));
	printf("second line:%s \n", get_next_line(fd));
	printf("third line:%s \n", get_next_line(fd));
	printf("fourth line:%s \n", get_next_line(fd));
	return (0);
}
