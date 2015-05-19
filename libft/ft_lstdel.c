/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:06:24 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 14:57:27 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cursor;
	t_list	*cursor2;

	cursor = *alst;
	while (cursor && cursor->next)
	{
		cursor2 = cursor;
		cursor = cursor->next;
		ft_lstdelone(&cursor2, del);
	}
	ft_lstdelone(&cursor, del);
	*alst = NULL;
}
