# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 01:50:20 by hyjeong           #+#    #+#              #
#    Updated: 2022/07/12 02:33:34 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = philo

SRCS = philo.c check_args.c check_death.c utils.c print.c end_program.c monitor.c data_fill.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lpthread
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "clean"

fclean: clean
	@rm -rf $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fclean"

re: fclean all

.PHONY: all clean fclean re