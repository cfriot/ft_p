/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:15:19 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:36:38 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nbword(char const *s, char c)
{
	int		i;
	int		cpt;
	char	*stmp;
	int		p;

	stmp = (char *)s;
	i = 0;
	cpt = 0;
	p = 0;
	while (stmp[i])
	{
		while (stmp[i] == c && stmp[i])
			i++;
		while (stmp[i] && stmp[i] != c)
		{
			i++;
			p = 1;
		}
		if (p == 1)
			cpt++;
		p = 0;
	}
	return (cpt);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		p;
	int		nb_w;
	int		size_w;

	if (!s)
		return (NULL);
	p = 0;
	i = 0;
	nb_w = ft_nbword(s, c);
	tab = (char**)malloc(sizeof(char *) * ft_nbword(s, c) + 1);
	while (p < nb_w)
	{
		size_w = 0;
		while (*(s + i) == c && *(s + i))
			i++;
		while (*(s + i + size_w) != c && *(s + i + size_w))
			size_w++;
		tab[p] = ft_strsub(s, (unsigned int)i, (size_t)size_w);
		i += size_w;
		p++;
	}
	tab[p] = 0;
	return (tab);
}
