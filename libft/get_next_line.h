/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:43:53 by cfriot            #+#    #+#             */
/*   Updated: 2015/03/20 18:01:54 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# define BUFF_SIZE 100000

typedef struct		s_lst
{
	int				key;
	char			*rmn;
	struct s_lst	*next;
}					t_lst;
void				ft_lstadd_line(t_lst *begin, int const fd,
					char **line, int *end);
char				*ft_get_line(int const fd, char **line, int *end);
char				*ft_get_rmn(int const fd, char **line, int *end, char *rmn);
t_lst				*ft_lstnew_line(int const fd, char **line, int *end);
int					get_next_line(int const fd, char **line);
#endif
