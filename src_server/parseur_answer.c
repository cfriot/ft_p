/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:47:12 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/11 18:25:49 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char	*ft_parse_ans(int ret)
{
	if (ret == 1)
		return ("SUCCESS");
	else if (ret == -10)
		return ("Good bye!");
	else if (ret == -1)
		return ("ERROR : Too many args");
	else if (ret == -2)
		return ("ERROR : You can't go above your main directory");
	else if (ret == -3)
		return ("ERROR : Path not found");
	else if (ret == -4)
		return ("ERROR : File is a directory");
	else if (ret == -5)
		return ("ERROR : You don't have the right to open/use this file");
	else if (ret == -6)
		return ("ERROR : File not found");
	else if (ret == -8)
		return ("ERROR : Path is not a directory");
	else if (ret == -11 || ret == -7)
		return ("ERROR : main ressources has failed");
	else if (ret == -12)
		return ("ERROR : Command not found");
	else
		return ("ERROR");
}
