/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 11:38:22 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/11 18:15:22 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ft_check_line(char *str, t_magic *magic)
{
	char		**info;
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	info = ft_strsplit(str, ' ');
	return (ft_parse(info, magic));
}

int		ft_parse(char **info, t_magic *magic)
{
	int		ret;

	ret = 0;
	if (info && ft_tablen(info) >= 1)
	{
		if (ft_tablen(info) >= 1 && ft_strcmp(info[0], "cd") == 0)
			return (ft_do_cd(info, magic));
		else if (ft_tablen(info) == 2 && ft_strcmp(info[0], "get") == 0)
			return (ft_get_files(info, magic));
		else if (ft_tablen(info) == 2 && ft_strcmp(info[0], "put") == 0)
			return (ft_server_receve_data(info, magic));
		else if (ft_tablen(info) >= 1 && ft_strcmp(info[0], "quit") == 0)
			return (-10);
		else
			return (ft_test_exec(info, magic));
	}
	return (-100);
}

int		ft_check_access_exe(char *path, char *info)
{
	struct stat		*buf;
	int				retstat;

	if ((buf = malloc(sizeof(struct stat))))
	{
		retstat = stat(ft_strjoin(path, info), buf);
		if (retstat == 0)
		{
			if (!(buf->st_mode & S_IXUSR))
			{
				free(buf);
				return (-5);
			}
			else
			{
				free(buf);
				return (0);
			}
		}
		free(buf);
		return (-6);
	}
	return (-7);
}

int		ft_test_exec(char **info, t_magic *magic)
{
	char	*call;
	char	**path;
	int		i;
	int		access;

	i = -1;
	access = 0;
	call = ft_strjoin("/", info[0]);
	path = ft_strsplit(magic->path, ':');
	while (path && path[++i])
	{
		if ((access = ft_check_access_exe(path[i], call)) == 0)
		{
			info[0] = getcwd(0, 0);
			return (ft_to_fork_exec(path[i], call, info, magic));
		}
	}
	if (path)
		ft_clear_tab(path);
	ft_fork_wait(magic->cs, ft_transform(ft_itoa(-1)));
	return (-12);
}

int		ft_to_fork_exec(char *path, char *call, char **info, t_magic *magic)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait4(0, 0, 0, 0);
		write(magic->cs, "\0", 1);
		return (1);
	}
	else if (father == 0)
	{
		ft_fork_wait(magic->cs, ft_transform(ft_itoa(1)));
		dup2(magic->cs, 1);
		dup2(magic->cs, 2);
		execv(ft_strjoin(path, call), info);
		exit(2);
	}
	else
		return (-11);
}
