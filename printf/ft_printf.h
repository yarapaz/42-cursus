/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:41:48 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/09/05 18:08:30 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unputnbr(unsigned int n);
int		ft_puthexa(unsigned int n, char *base);
int		ft_hexamax(unsigned int n, char *base);
int		ft_hexpoint(unsigned long n, char *base);
int		ft_printf(char const *type, ...);
int		ft_type(char *type, va_list args);

#endif