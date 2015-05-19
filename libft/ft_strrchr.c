/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:33:41 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:36:27 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	void	*stmp;

	stmp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			stmp = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		stmp = (char *)(s + i);
	return (stmp);
}
