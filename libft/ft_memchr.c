/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:35:46 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:29:19 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (NULL);
	if (*(unsigned char *)s == (unsigned char)c)
		return ((void *)s);
	else
		return (ft_memchr(s + 1, c, n - 1));
}
