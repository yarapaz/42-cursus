/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:49:10 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/07 19:25:46 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		original;
    int		feature;
	// char 	*puntero = "hola";

    original = printf(" sdfdfgasfsdf %c%%  sdfasdfasdfasdf %x %d" , 'A', 23423, 7);
    feature = ft_printf(" sdfdfgasfsdf %c%%  sdfasdfasdfasdf %x %d" , 'A', 23423, 7);

	printf(" 1) %d ", original);
	printf(" 2) %d ", feature);

    return (0);    
}