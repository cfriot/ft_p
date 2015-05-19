/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:54:33 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:06:33 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*strnew;
	size_t	i;

	i = -1;
	strnew = NULL;
	strnew = (char *)malloc(sizeof(char) * size + 1);
	while (++i < size && strnew)
		strnew[i] = 0;
	strnew[i] = 0;
	return (strnew);
}
