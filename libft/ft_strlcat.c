/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:17:36 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:34:36 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size2;
	size_t	i;

	size2 = ft_strlen(dst);
	i = 0;
	if (size2 >= size)
		return (size + ft_strlen((char *)src));
	while (src[i] && i < size - size2 - 1)
	{
		dst[i + size2] = src[i];
		i++;
	}
	dst[i + size2] = 0;
	return (ft_strlen((char *)src) + size2);
}
