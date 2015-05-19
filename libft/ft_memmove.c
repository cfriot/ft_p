/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:41:31 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:30:22 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc(len);
	tmp = ft_strncpy(tmp, (char *)src, len);
	dst = ft_strncpy((char *)dst, tmp, len);
	free(tmp);
	return (dst);
}
