/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:53:20 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:40:23 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*stmp1;
	char	*stmp2;
	size_t	i;

	stmp1 = (char *)s1;
	stmp2 = (char *)s2;
	i = 0;
	while (stmp1[i] == stmp2[i] && i < n)
		i++;
	if (n == i)
		return (0);
	else
		return ((unsigned char)stmp1[i] - (unsigned char)stmp2[i]);
}
