/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:52:19 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/07 14:08:25 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int cpt;

	cpt = 0;
	if (nbr == -2147483648)
	{
		ft_putnbr_fd(nbr / 10, fd);
		cpt = 1;
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else if (cpt != 1)
		ft_putchar_fd(nbr + 48, fd);
	else
		ft_putchar_fd('8', fd);
}
