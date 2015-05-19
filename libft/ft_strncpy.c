/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 12:45:40 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:35:49 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t index;

	index = 0;
	while ((src[index] != '\0') && (index < n))
	{
		dst[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dst[index] = 0;
		index++;
	}
	return (dst);
}
