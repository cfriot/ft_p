/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:45:55 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:36:13 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	cpt;
	void	*stmp;

	i = -1;
	cpt = 0;
	stmp = (char *)s1;
	while (s1[++i] && s2[cpt] && i < n)
	{
		if (s1[i] == s2[cpt])
			cpt++;
		else
			cpt = 0;
	}
	if ((int)cpt == ft_strlen((char *)s2))
		return (stmp + i - cpt);
	return (0);
}
