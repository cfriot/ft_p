/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 19:23:21 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:35:30 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;

	index = 0;
	while (s1[index] == s2[index] && index < n)
		index++;
	if (n == index)
		return (0);
	else if (s1[index] > s2[index])
		return (1);
	else
		return (-1);
}
