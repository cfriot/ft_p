/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:30:01 by cfriot            #+#    #+#             */
/*   Updated: 2015/03/23 16:57:36 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*dst;

	dst = NULL;
	i = 0;
	if (s1 && s2)
		dst = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (dst && s1 && s2)
	{
		while (*s1)
		{
			dst[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			dst[i] = *s2;
			i++;
			s2++;
		}
		dst[i] = 0;
		return (dst);
	}
	return (0);
}
