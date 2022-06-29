# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 16:18:35 by hyjeong           #+#    #+#              #
#    Updated: 2022/06/29 16:27:11 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, name, all, re

NAME = megaphone

SRCS = src/megaphone.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

REM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(REM) $(NAME)

fclean:
	$(REM) $(NAME)

re: fclean all
