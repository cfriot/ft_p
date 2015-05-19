/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rankierm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:09:41 by rankierm          #+#    #+#             */
/*   Updated: 2014/11/07 18:19:49 by rankierm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (s && str)
	{
		str = ft_strncpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	else
		return (NULL);
}
