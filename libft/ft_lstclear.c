/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:42 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/23 17:25:09 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	if (lst == NULL)
		return ;
	else
	{
		aux = *lst;
		while (aux != NULL)
		{
			aux2 = aux->next;
			ft_lstdelone(aux, del);
			aux = aux2;
		}
		*lst = NULL;
	}
}
