# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 22:29:19 by suko              #+#    #+#              #
#    Updated: 2022/04/20 03:01:07 by hyunjoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

IDIR=include/

SDIR=src/
SRCS=push_swap.c input_helper.c operation.c operation_helper.c sort_helper.c\
	quick_sort.c order_helper.c order_helper2.c
SRCS_DIR=$(addprefix $(SDIR), $(SRCS))

OBJS=$(SRCS_DIR:.c=.o)

LIB=libft.a
LNAME=ft
LDIR=./libft

CC=gcc
FLAGS=-I$(IDIR) -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c

$(NAME): $(SRCS_DIR) include/push_swap.h
	make all -C libft
	$(CC) $(FLAGS) $(SRCS_DIR) -o $@ -L$(LDIR) -l$(LNAME)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
