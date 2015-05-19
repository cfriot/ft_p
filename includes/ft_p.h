/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:35:42 by cfriot            #+#    #+#             */
/*   Updated: 2015/05/19 13:52:08 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/stat.h>

# define SIZE_DATA 4096

typedef struct	s_magic
{
	int			cs;
	char		*home_serv;
	char		*pwd;
	char		*oldpwd;
	char		*path;
}				t_magic;

int				ft_check_line(char *str, t_magic *magic);
int				ft_parse(char **info, t_magic *magic);
int				ft_do_cd(char **info, t_magic *magic);
int				ft_tablen(char **info);
int				ft_get_files(char **info, t_magic *magic);
int				ft_server_receve_data(char **info, t_magic *magic);
int				ft_to_fork_exec(char *path, char *call, char **info,
				t_magic *magic);
int				ft_end_transfert(char *buf, size_t size);
int				ft_connect(t_magic *magic);
int				ft_get_user(int sock);
int				ft_check_access_put(char *path);
int				ft_check_access(char *path);
int				ft_test_exec(char **info, t_magic *magic);
char			*ft_parse_ans(int ret);
char			*ft_clean_line(char *buf);
char			*ft_transform(char *size);
int				ft_parse_entry(char *buf, int sock);
void			ft_prepare_to_receve(int sock, char **info);
void			ft_prepare_to_send(int sock, char **info);
void			ft_clear_tab(char **info);
void			ft_fork_wait(int sock, char *size);
void			ft_read_ans(int sock);
#endif
