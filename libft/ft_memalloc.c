/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:48:04 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:27:48 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	ptr = (char *)malloc(size);
	while (ptr && i < size)
	{
		*(ptr + i) = 0;
		i++;
	}
	return ((void *)ptr);
}
