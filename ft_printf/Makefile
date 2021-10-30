# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 01:34:26 by hyunjoo           #+#    #+#              #
#    Updated: 2021/10/30 21:06:18 by hyunjoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_printf.c flag_format.c\
		set_flag.c write_all.c write_all2.c

FLAGS =	-Wall -Wextra -Werror

SUB_DIR = libft

all: $(NAME)

$(NAME): lib

bonus: lib
	ar -cr libftprintf_bonus.a *.o $(SUB_DIR)/*.o

sub_lib:
	cd $(SUB_DIR) && $(MAKE)

lib: objects sub_lib
	ar -cr $(NAME) *.o $(SUB_DIR)/*.o

objects:
	gcc -c $(FLAGS) $(SRC)
	
clean: libftclean
	rm -f *.o

libftclean:
	cd libft && $(MAKE) clean

fclean: clean libftfclean
	rm -f $(NAME)
	rm -f libftprintf_bonus.a

libftfclean: 
	cd libft && $(MAKE) fclean

re: fclean all