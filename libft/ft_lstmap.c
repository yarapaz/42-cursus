/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapaz-go <yapaz-go@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:18:48 by yapaz-go          #+#    #+#             */
/*   Updated: 2023/03/23 16:48:51 by yapaz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final_list;

	if (lst == NULL)
		return (NULL);
	final_list = ft_lstnew(f(lst->content));
	if (!final_list)
		ft_lstdelone(final_list, del);
	final_list->next = ft_lstmap(lst->next, f, del);
	return (final_list);
}
