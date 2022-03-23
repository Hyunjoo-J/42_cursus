# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 19:23:44 by hyjeong           #+#    #+#              #
#    Updated: 2022/03/23 20:07:13 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

IDIR=include/

SDIR=src/
SRCS=so_long.c draw.c get_next_line.c key.c parse.c util.c
SRCS_DIR=$(addprefix $(SDIR), $(SRCS))

OBJS=$(SRCS_DIR:.c=.o)

LIBFT=libft.a
LIBMLX=libmlx.a

FLAGS=-I$(IDIR) -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c

$(NAME): $(SRCS_DIR) include/so_long.h
	make all -C minilibx
	make all -C libft
	mv minilibx/$(LIBMLX) .
	mv libft/$(LIBFT) .
	gcc $(FLAGS) -framework OpenGL -framework AppKit $(SRCS_DIR) -o $(NAME) -lm -L. $(LIBMLX) $(LIBFT)

clean:
	rm -f $(OBJS)
	make clean -C minilibx
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBMLX)
	rm -f $(LIBFT)

re: fclean all
