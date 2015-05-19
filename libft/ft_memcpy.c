/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:48:28 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:39:21 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dsttmp;
	char *srctmp;

	dsttmp = dst;
	srctmp = (char *)src;
	while (n > 0)
	{
		dsttmp[n - 1] = srctmp[n - 1];
		n--;
	}
	dst = dsttmp;
	return (dst);
}
