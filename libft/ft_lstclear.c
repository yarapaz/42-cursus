/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:42 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:14 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst[0] == NULL)
		return ;
	else
	{
		aux = lst[0];
		while (lst[0] != NULL)
		{
			ft_lstdelone(, del);
			aux = aux->next;
		}
	}
}
