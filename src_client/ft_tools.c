/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:25:20 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:49:39 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char	*ft_transform(char *size)
{
	char	*nw_str;
	int		test;
	int		i;
	int		y;

	y = 0;
	i = -1;
	nw_str = malloc(11);
	test = ft_strlen(size);
	test = 9 - test;
	while (++i < test)
		nw_str[i] = ' ';
	while (size[y])
	{
		nw_str[i] = size[y];
		i++;
		y++;
	}
	return (nw_str);
}

int		ft_tablen(char **info)
{
	int		i;

	i = -1;
	if (info)
	{
		while (info[++i])
			;
	}
	return (i);
}

char	*ft_clean_line(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n' || buf[i] == '\t')
			buf[i] = ' ';
	}
	return (buf);
}

void	ft_clear_tab(char **info)
{
	int		i;

	i = 0;
	if (info)
	{
		while (info[i])
		{
			free(info[i]);
			i++;
		}
		free(info);
	}
}

void	ft_fork_wait(int sock, char *size)
{
	pid_t	pid;

	pid = fork();
	if (pid != -1)
	{
		if (pid == 0)
		{
			send(sock, size, 10, 0);
			exit(0);
		}
		else
			wait4(0, 0, 0, 0);
	}
	else
	{
		ft_putstr("Error while forking");
		exit(0);
	}
}
