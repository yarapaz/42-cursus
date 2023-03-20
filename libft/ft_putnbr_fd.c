/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:18 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/13 20:57:52 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
		ft_putchar_fd((n + '0'), fd);
	else if (n > 0)
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd);
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(((n % 10) + '0'), fd);
		}
	}
}
