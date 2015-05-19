# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by tdurand           #+#    #+#              #
#    Updated: 2015/05/19 13:55:36 by cfriot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

all :
	@make -C src_server/
	@make -C src_client/
	@make -C libft/


clean :
	@make -C libft/ clean
	@make -C src_server/ clean
	@make -C src_client/ clean

fclean : allclean

allclean :
	@make -C libft/ fclean
	@make -C src_server/ fclean
	@make -C src_client/ fclean

re : fclean all
