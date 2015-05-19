/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 12:07:00 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/12 15:39:39 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ft_go_home(t_magic *magic)
{
	if (chdir(magic->home_serv) == 0)
	{
		if (magic->oldpwd != NULL)
			free(magic->oldpwd);
		magic->oldpwd = ft_strdup(magic->pwd);
		magic->pwd = getcwd(NULL, 0);
		return (1);
	}
	else
		return (-3);
}

int		ft_go_back(char **info, t_magic *magic)
{
	if (ft_strlen(info[1]) == 1 ||
			(ft_strlen(info[1]) == 2 && info[1][2] == '\n'))
	{
		if (chdir(magic->oldpwd) == 0)
		{
			free(magic->oldpwd);
			magic->oldpwd = ft_strdup(magic->pwd);
			magic->pwd = getcwd(NULL, 0);
			return (1);
		}
		else
			return (-3);
	}
	return (-3);
}

int		ft_do_cd_path(char **info, t_magic *magic)
{
	int		ret;

	ret = ft_check_access(info[1]);
	if (chdir(info[1]) == 0 && ret == -4)
	{
		if (ft_strstr(getcwd(NULL, 0), magic->home_serv) == NULL)
		{
			chdir(magic->pwd);
			return (-2);
		}
		if (magic->oldpwd != NULL)
			free(magic->oldpwd);
		magic->oldpwd = ft_strdup(magic->pwd);
		magic->pwd = getcwd(NULL, 0);
		return (1);
	}
	if (ret == -5)
		return (-5);
	else if (ret == -6)
		return (-3);
	return (-8);
}

int		ft_do_cd_from_home(char **info, t_magic *magic)
{
	char	*newpath;

	newpath = ft_strjoin(magic->home_serv, info[1] + 1);
	if (chdir(newpath) == 0)
	{
		if (ft_strstr(getcwd(NULL, 0), magic->home_serv) == NULL)
		{
			chdir(magic->pwd);
			free(newpath);
			return (-2);
		}
		if (magic->oldpwd != NULL)
			free(magic->oldpwd);
		magic->oldpwd = ft_strdup(magic->pwd);
		magic->pwd = getcwd(NULL, 0);
		free(newpath);
		return (1);
	}
	free(newpath);
	return (-3);
}

int		ft_do_cd(char **info, t_magic *magic)
{
	if (ft_tablen(info) == 1 || ft_strcmp(info[1], "~") == 0)
		return (ft_go_home(magic));
	else if (ft_tablen(info) == 2)
	{
		if (ft_strcmp(info[1], "-") == 0)
			return (ft_go_back(info, magic));
		else if (info[1][0] != '~')
			return (ft_do_cd_path(info, magic));
		else
			return (ft_do_cd_from_home(info, magic));
	}
	else
		return (-1);
}
