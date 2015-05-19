/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:13:31 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/11 17:33:54 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ft_end_transfert(char *buf, size_t size)
{
	size_t		i;
	int			cpt;

	i = 0;
	cpt = 0;
	while (i < size && cpt != 3)
	{
		if (buf[i] == '\0')
			cpt++;
		else
			cpt = 0;
		i++;
	}
	if (cpt == 3)
		return (i);
	return (-1);
}

int		ft_check_access_put(char *path)
{
	struct stat	*buf;
	int			retstat;
	char		*call;

	if ((buf = malloc(sizeof(struct stat))))
	{
		call = getcwd(0, 0);
		call = ft_strjoin(call, "/");
		retstat = stat(ft_strjoin(call, path), buf);
		if (retstat == 0)
		{
			if (!(buf->st_mode & S_IRUSR))
				return (-2);
			else if ((buf->st_mode & S_IFDIR))
				return (-3);
			else
				return (1);
		}
		return (-1);
	}
	return (-7);
}
