/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 15:12:17 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:44:37 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ft_get_user(int sock)
{
	char	*line;
	char	*size;
	char	buf[1024];
	char	entry[1024];
	int		ret;

	line = NULL;
	ret = recv(sock, buf, 23, 0);
	buf[ret] = 0;
	size = malloc(11);
	while (ft_strcmp(buf, "Connected!") != 0)
	{
		ft_putstr(buf);
		ret = read(0, entry, 1023);
		entry[ret] = 0;
		size = ft_transform(ft_itoa(ret));
		ft_fork_wait(sock, size);
		send(sock, entry, ret, 0);
		ret = recv(sock, size, 10, 0);
		ret = recv(sock, buf, ft_atoi(size), 0);
		buf[ret] = 0;
	}
	lseek(sock, 0, SEEK_END);
	return (1);
}
