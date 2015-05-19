/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 11:39:16 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:42:27 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

t_magic	ft_ini_magic(void)
{
	t_magic		magic;

	magic.home_serv = getcwd(NULL, 0);
	magic.pwd = getcwd(NULL, 0);
	magic.oldpwd = NULL;
	magic.path = ft_strdup("/usr/local/bin:/usr/bin:/bin:/usr/sbin");
	return (magic);
}

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("Bind error");
		exit(2);
	}
	if (listen(sock, 42) == -1)
		ft_putendl("listen error");
	return (sock);
}

void	dialog(t_magic magic)
{
	char		*buf;
	char		*size;
	int			ret;
	int			exit;

	exit = 1;
	buf = (char *)malloc(1024);
	size = (char *)malloc(10);
	while (exit)
	{
		ret = recv(magic.cs, size, 10, 0);
		ret = recv(magic.cs, buf, ft_atoi(size), 0);
		buf[ret] = 0;
		exit = ft_check_line(buf, &magic);
		ret = exit;
		ft_bzero(size, 10);
		buf = ft_strcpy(buf, ft_parse_ans(ret));
		size = ft_transform(ft_itoa(ft_strlen(buf)));
		ft_fork_wait(magic.cs, size);
		ret = send(magic.cs, buf, ft_strlen(buf), 0);
	}
}

void	ft_fork(int sock)
{
	pid_t					pid;
	struct sockaddr_in		csin;
	unsigned int			cslen;
	t_magic					magic;

	magic = ft_ini_magic();
	while (1)
	{
		magic.cs = accept(sock, (struct sockaddr*)&csin, &cslen);
		if (magic.cs != -1)
			pid = fork();
		if (magic.cs != -1 && pid != -1)
		{
			if (pid == 0)
			{
				ft_connect(&magic);
				dialog(magic);
				close(magic.cs);
				exit(1);
			}
		}
		else
			ft_putendl("Error while forking");
	}
}

int		main(int ac, char **av)
{
	int						port;
	int						sock;

	if (ac != 2)
		printf("Usage : ./serveur NumPort\n");
	else if (ft_isnum(av[1]) == 0)
	{
		port = ft_atoi(av[1]);
		sock = create_server(port);
		ft_fork(sock);
		close(sock);
	}
	else
		printf("Usage : NumPort must be numbers\n");
	return (0);
}
