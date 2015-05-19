/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:25:15 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:35:04 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = NULL;
	if (s && f)
	{
		dst = (char *)malloc(ft_strlen(s + 1));
		while (s[i])
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		dst[i] = 0;
	}
	return (dst);
}
