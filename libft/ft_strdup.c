/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/20 13:07:11 by exam              #+#    #+#             */
/*   Updated: 2015/04/21 16:13:40 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src)
	{
		dest = (char *)malloc(sizeof(char) * ft_strlen(src));
		if (dest)
		{
			while (src[i])
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
		return (dest);
	}
	else
		return (NULL);
}
