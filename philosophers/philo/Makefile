# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 15:11:21 by hyjeong           #+#    #+#              #
#    Updated: 2022/05/11 15:13:33 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

IDIR=include/

SDIR=src/
SRCS=philo.c util.c util2.c action.c
SRCS_DIR=$(addprefix $(SDIR), $(SRCS))

OBJS=$(SRCS_DIR:.c=.o)

CC=gcc
FLAGS=-I$(IDIR) -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c

$(NAME): $(SRCS_DIR) include/philo.h
	$(CC) $(FLAGS) $(SRCS_DIR) -o $@ -lpthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
