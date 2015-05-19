/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:00:19 by cfriot            #+#    #+#             */
/*   Updated: 2015/02/13 03:55:02 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int cpt;
	int cpt2;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			cpt = i;
			cpt2 = 0;
			while (s1[cpt] == s2[cpt2])
			{
				cpt++;
				cpt2++;
				if (s2[cpt2] == 0)
					return ((char *)(s1 + i));
			}
		}
		i++;
	}
	return (NULL);
}
