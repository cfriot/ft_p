# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/10 15:21:24 by cfriot            #+#    #+#              #
#    Updated: 2015/05/19 13:58:55 by cfriot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = client.c \
	  parseur_entry.c \
	  ft_tools.c      \
	  ft_check.c      \
	  ft_get_user.c

OBJ = $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all : libft $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ../libft/libft.a 
	@echo "!"
	@echo "$(NAME) compiled\033[0m"
	@mv $(NAME) ../

libft :
	@make -C ../libft/

%.o : %.c
	@$(CC) -c $(CFLAGS) -I../includes/ -I../libft/includes $<
	@printf "\033[32m."

clean :
	@make -C ../libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mclient objects deleted\033[0m"

fclean : allclean
	@/bin/rm -f ../$(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

allclean :
	@make -C ../libft/ fclean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mclient objects deleted\033[0m"

re : fclean all
