/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:38:11 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 14:56:56 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = NULL;
	if (content)
		tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content && content_size)
		{
			tmp->content = (void *)malloc(content_size);
			tmp->content = ft_memmove(tmp->content, content, content_size);
		}
		else
			tmp->content = NULL;
		if (!content)
			tmp->content_size = 0;
		else
			tmp->content_size = content_size;
		tmp->next = NULL;
	}
	return (tmp);
}
