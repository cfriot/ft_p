/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 13:30:32 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:50:18 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int			ft_parse_entry(char *buf, int sock)
{
	char	**info;

	buf = ft_clean_line(buf);
	info = ft_strsplit(buf, ' ');
	if (info && info[0])
	{
		if (ft_strcmp(info[0], "get") == 0)
			ft_prepare_to_receve(sock, info);
		else if (ft_strcmp(info[0], "put") == 0)
			ft_prepare_to_send(sock, info);
		else if (ft_strcmp(info[0], "quit") == 0)
			return (0);
		else if (ft_strcmp(info[0], "cd") != 0)
			ft_read_ans(sock);
		ft_clear_tab(info);
		return (1);
	}
	return (-1);
}

void		ft_read_ans(int sock)
{
	char	buf[2];
	int		ret;
	char	*size;

	size = malloc(11);
	ret = recv(sock, size, 10, 0);
	if (ft_atoi(size) > 0)
	{
		while ((ret = read(sock, buf, 1)) > 0 && buf[0] != 0)
		{
			buf[1] = 0;
			ft_putstr(buf);
		}
	}
}

static void	ft_send_data(int fd, int sock)
{
	char	*size;
	char	buf[SIZE_DATA];
	int		check;
	size_t	ret;

	check = 0;
	if (fd > 0)
	{
		while ((ret = read(fd, buf, SIZE_DATA)) > 0)
			check += ret;
		lseek(fd, 0, SEEK_SET);
		size = ft_transform(ft_itoa(check));
		send(sock, size, 10, 0);
		while (check > 0)
		{
			ret = read(fd, buf, SIZE_DATA);
			send(sock, buf, ret, 0);
			check -= ret;
		}
	}
}

void		ft_prepare_to_send(int sock, char **info)
{
	int		fd;
	char	*size;
	int		ret;

	fd = 0;
	if (ft_tablen(info) == 2)
	{
		ret = ft_check_access_put(info[1]);
		if (ret > 0)
		{
			fd = open(info[1], O_RDONLY);
			ft_send_data(fd, sock);
		}
		if (fd > 0)
			close(fd);
		else
		{
			size = ft_transform(ft_itoa(ret));
			send(sock, size, 10, 0);
		}
	}
	else
		ft_putendl("Usage: put myfiles");
}

void		ft_prepare_to_receve(int sock, char **info)
{
	char	buf[SIZE_DATA];
	char	size[10];
	size_t	ret;
	int		fd;
	int		tot_size;

	recv(sock, size, 10, 0);
	tot_size = ft_atoi(size);
	if (tot_size > 0)
	{
		fd = open(info[1], O_CREAT | O_WRONLY, S_IRUSR | S_IRGRP | S_IWUSR);
		while (tot_size > SIZE_DATA)
		{
			ret = recv(sock, buf, SIZE_DATA, 0);
			tot_size -= SIZE_DATA;
			write(fd, buf, ret);
		}
		if (tot_size > 0)
		{
			ret = recv(sock, buf, tot_size, 0);
			write(fd, buf, ret);
		}
		close(fd);
	}
}
