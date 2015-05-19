/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:34:11 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:39:39 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*btmp;
	size_t	i;

	i = 0;
	btmp = b;
	while (i < len)
	{
		btmp[i] = c;
		i++;
	}
	return (btmp);
}
