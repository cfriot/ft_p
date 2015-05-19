/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 14:11:48 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:16:00 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int		ft_check_password(char **info, t_magic *magic)
{
	int		ret;
	char	*size;
	char	line[1024];

	size = malloc(11);
	ret = recv(magic->cs, size, 10, 0);
	ret = recv(magic->cs, line, ft_atoi(size), 0);
	line[ret] = 0;
	if (ft_strncmp(info[1], line, ft_strlen(line) - 1) == 0 &&
			ft_strlen(info[1]) == ft_strlen(line) - 1)
	{
		size = ft_transform(ft_itoa(10));
		send(magic->cs, size, 10, 0);
		send(magic->cs, "Connected!", 10, 0);
		return (1);
	}
	else
	{
		size = ft_transform(ft_itoa(32));
		send(magic->cs, size, 10, 0);
		send(magic->cs, "Incorrect password, try again : ", 32, 0);
		free(size);
	}
	return (0);
}

static int		ft_get_password(char **info, t_magic *magic)
{
	int		find;
	char	*size;

	find = 0;
	size = ft_transform(ft_itoa(29));
	send(magic->cs, size, 10, 0);
	send(magic->cs, "Please enter your password : ", 29, 0);
	while (find == 0)
		find = ft_check_password(info, magic);
	if (chdir(info[0]) == 0)
	{
		magic->pwd = getcwd(NULL, 0);
		magic->home_serv = getcwd(NULL, 0);
	}
	return (1);
}

static void		ft_create_account(t_magic *magic, int fd, char *username)
{
	char	*size;
	char	line[1024];
	int		find;

	write(fd, username, ft_strlen(username) - 1);
	username[ft_strlen(username) - 1] = 0;
	write(fd, ":", 1);
	size = ft_transform(ft_itoa(36));
	send(magic->cs, size, 10, 0);
	send(magic->cs, "New user, please enter a password : ", 36, 0);
	recv(magic->cs, size, 10, 0);
	find = recv(magic->cs, line, ft_atoi(size), 0);
	write(fd, line, find);
	mkdir(username, 0755);
	if (chdir(username) == 0)
	{
		magic->pwd = getcwd(NULL, 0);
		magic->home_serv = getcwd(NULL, 0);
	}
	size = ft_transform(ft_itoa(10));
	send(magic->cs, size, 10, 0);
	send(magic->cs, "Connected!", 10, 0);
}

static int		ft_search_user(t_magic *magic, char *username, int fd)
{
	char	*line2;
	char	**info;

	while (get_next_line(fd, &line2) > 0)
	{
		info = ft_strsplit(line2, ':');
		if (ft_strncmp(info[0], username, ft_strlen(username) - 1) == 0 &&
				ft_strlen(info[0]) == ft_strlen(username) - 1)
		{
			ft_get_password(info, magic);
			return (1);
		}
		ft_clear_tab(info);
	}
	return (0);
}

int				ft_connect(t_magic *magic)
{
	int		fd;
	char	line[1024];
	char	*size;
	int		find;

	fd = open("log", O_RDWR | O_CREAT | O_APPEND);
	chmod("log", 0755);
	size = malloc(11);
	send(magic->cs, "Enter your user name : ", 23, 0);
	recv(magic->cs, size, 10, 0);
	find = recv(magic->cs, line, ft_atoi(size), 0);
	line[find] = 0;
	find = ft_search_user(magic, line, fd);
	if (find == 0)
		ft_create_account(magic, fd, line);
	close(fd);
	return (1);
}
