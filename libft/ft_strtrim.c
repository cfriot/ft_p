/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:56 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:37:33 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	int		size;
	char	*dst;

	if (!s)
		return (NULL);
	beg = 0;
	size = 0;
	end = ft_strlen((char *)s) - 1;
	while (*(s + beg) == ' ' || *(s + beg) == '\t' || *(s + beg) == '\n')
		beg++;
	if (beg != ft_strlen((char *)s))
		while (*(s + end) == ' ' || *(s + end) == '\t' || *(s + end) == '\n')
			end--;
	if (!(dst = (char *)malloc(end - beg + 1)))
		return (NULL);
	while (beg <= end)
	{
		*dst = *(s + beg++);
		dst++;
		size++;
	}
	*dst = 0;
	return (dst - size);
}
