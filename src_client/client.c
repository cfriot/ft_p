/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 15:45:45 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:49:17 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

static int		create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("Connect error");
		exit(2);
	}
	return (sock);
}

static void		prompt(int sock)
{
	int		ret;
	char	ans[1024];
	char	buf[1024];
	char	*size;
	int		exit;

	exit = 1;
	while (exit)
	{
		ft_putstr_fd("\033[32m$:)> \033[0m", 1);
		ret = read(0, buf, 1023);
		buf[ret] = '\0';
		size = ft_transform(ft_itoa(ret));
		ft_fork_wait(sock, size);
		send(sock, buf, ft_atoi(size), 0);
		exit = ft_parse_entry(buf, sock);
		ret = recv(sock, size, 10, 0);
		ret = recv(sock, ans, ft_atoi(size), 0);
		ans[ret] = 0;
		ft_putendl(ans);
	}
}

int				main(int ac, char **av)
{
	int					port;
	int					sock;

	if (ac == 3 && ft_isnum(av[2]) == 0)
	{
		port = ft_atoi(av[2]);
		sock = create_client(av[1], port);
		ft_get_user(sock);
		prompt(sock);
		close(sock);
	}
	else if (ft_isnum(av[2]) != 0)
		printf("Usage : Port must be numbers\n");
	else
		printf("Usage : <addr> <port>\n");
	return (0);
}
