/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:15:21 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:34:58 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = -1;
	if (s && f)
	{
		dst = (char *)malloc(1 * ft_strlen((char *)s) + 1);
		while (s[++i])
			dst[i] = f(s[i]);
		dst[i] = 0;
		return (dst);
	}
	else
		return (NULL);
}
