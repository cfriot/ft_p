/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:48:28 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/06 17:05:49 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dsttmp;
	char	*srctmp;
	size_t	i;

	i = 0;
	dsttmp = dst;
	srctmp = (char *)src;
	while (i < n)
	{
		if (srctmp[i] == c)
		{
			dsttmp[i] = srctmp[i];
			return (dst + i + 1);
		}
		dsttmp[i] = srctmp[i];
		i++;
	}
	return (NULL);
}
