/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 15:58:51 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/12 15:44:30 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ft_check_access(char *path)
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
				return (-5);
			else if ((buf->st_mode & S_IFDIR))
				return (-4);
			else
				return (1);
		}
		else
			return (-6);
	}
	return (-7);
}

int		ft_send_data(int fd, t_magic *magic)
{
	char		buf[SIZE_DATA];
	char		*size;
	int			check;
	size_t		ret;

	if (fd > 0)
	{
		check = 0;
		while ((ret = read(fd, buf, SIZE_DATA)) > 0)
			check += ret;
		lseek(fd, 0, SEEK_SET);
		size = ft_transform(ft_itoa(check));
		send(magic->cs, size, 10, 0);
		while (check > 0)
		{
			ret = read(fd, buf, SIZE_DATA);
			send(magic->cs, buf, ret, 0);
			check -= ret;
		}
		return (1);
	}
	else
		return (-5);
}

int		ft_get_files(char **info, t_magic *magic)
{
	int		fd;
	int		ret;
	char	*size;

	fd = open(info[1], O_RDONLY);
	ret = ft_check_access(info[1]);
	if (ret > 0)
		ret = ft_send_data(fd, magic);
	if (ret < 0)
	{
		size = ft_transform(ft_strdup("-1"));
		send(magic->cs, size, 10, 0);
	}
	else
		close(fd);
	return (ret);
}

int		ft_parse_error_receve(int size)
{
	if (size == -2)
		return (-4);
	else if (size == -3)
		return (-5);
	else
		return (-6);
}

int		ft_server_receve_data(char **info, t_magic *magic)
{
	char	size[10];
	int		tot_size;
	int		ret;
	char	buf[SIZE_DATA];
	int		fd;

	recv(magic->cs, size, 10, 0);
	tot_size = ft_atoi(size);
	if (tot_size > 0)
		fd = open(info[1], O_CREAT | O_WRONLY, S_IRUSR | S_IRGRP | S_IWUSR);
	else
		return (ft_parse_error_receve(tot_size));
	while (tot_size > SIZE_DATA)
	{
		ret = recv(magic->cs, buf, SIZE_DATA, 0);
		tot_size -= ret;
		write(fd, buf, ret);
	}
	if (tot_size > 0)
	{
		ret = recv(magic->cs, buf, tot_size, 0);
		write(fd, buf, ret);
	}
	close(fd);
	return (1);
}
