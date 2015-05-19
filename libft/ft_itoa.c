/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:03:42 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:00:56 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_puissance(int c)
{
	int nb;

	nb = 1;
	while (c > 9 || c < -9)
	{
		nb++;
		c = c / 10;
	}
	return (nb);
}

static	char	*ft_itoaup(char *s, int c, int nb_digit)
{
	s[nb_digit] = 0;
	while (nb_digit >= 0)
	{
		s[nb_digit - 1] = (c % 10) + '0';
		nb_digit--;
		c = c / 10;
	}
	return (s);
}

static	char	*ft_itoadw(char *s, int c, int nb_digit)
{
	s[nb_digit + 1] = 0;
	while (nb_digit >= 0)
	{
		s[nb_digit] = -(c % 10) + '0';
		nb_digit--;
		c = c / 10;
	}
	s[0] = '-';
	return (s);
}

char			*ft_itoa(int c)
{
	char	*str;
	int		nb_digit;

	nb_digit = ft_puissance(c);
	if (c < 0)
	{
		str = (char *)malloc(nb_digit + 2);
		str = ft_itoadw(str, c, nb_digit);
	}
	else
	{
		str = (char *)malloc(nb_digit + 1);
		str = ft_itoaup(str, c, nb_digit);
	}
	return (str);
}
