/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:42:07 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 14:46:38 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*previous;
	t_list	*begin;

	begin = NULL;
	if (lst)
	{
		previous = ft_lstnew(lst->content, lst->content_size);
		if (!previous)
			return (0);
		previous = f(previous);
		begin = previous;
		lst = lst->next;
	}
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (!new)
			return (0);
		new = f(new);
		previous->next = new;
		previous = new;
		lst = lst->next;
	}
	return (begin);
}
