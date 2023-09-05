/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:49:10 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/08/09 20:11:10 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    int    original;
    int    copia;

    original = printf("original %d", 34);
    copia = ft_printf("copia %d", 34);

    printf("caracteres original %d", original);
    printf("caracteres copia %d", copia);
    
    return (0);    
}
