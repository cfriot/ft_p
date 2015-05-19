/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:52:19 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/06 15:51:26 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	int cpt;

	cpt = 0;
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10);
		cpt = 1;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (cpt != 1)
		ft_putchar(nbr + 48);
	else
		ft_putchar('8');
}
