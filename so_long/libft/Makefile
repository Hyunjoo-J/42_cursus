# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 18:48:21 by hyjeong           #+#    #+#              #
#    Updated: 2022/03/25 18:48:24 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_bzero.c			\
		ft_calloc.c			\
	   	ft_isalnum.c		\
	   	ft_isalpha.c 		\
		ft_isascii.c		\
	   	ft_isdigit.c		\
	   	ft_isprint.c		\
	   	ft_itoa.c			\
	   	ft_memchr.c			\
	   	ft_memcmp.c			\
	   	ft_memcpy.c			\
	   	ft_memmove.c		\
	   	ft_memset.c			\
	   	ft_putchar_fd.c		\
	   	ft_putendl_fd.c		\
	   	ft_putnbr_fd.c		\
	   	ft_putstr_fd.c		\
	   	ft_split.c			\
		ft_split_clear.c	\
	   	ft_strchr.c			\
	   	ft_strdup.c			\
	   	ft_striteri.c		\
	   	ft_strjoin.c		\
	   	ft_strlcat.c		\
		ft_strcpy.c			\
	   	ft_strlcpy.c		\
	   	ft_strlen.c			\
	   	ft_strmapi.c 		\
		ft_strcmp.c			\
		ft_strncmp.c		\
	   	ft_strnstr.c		\
	   	ft_strrchr.c		\
	   	ft_strtrim.c		\
	   	ft_substr.c			\
	   	ft_tolower.c		\
		ft_atoi.c			\
	   	ft_toupper.c		\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstbeforelast.c	\
		ft_lstlast.c		\
		ft_lstbeforelast.c	\
		ft_lstadd_back.c	\
		ft_lstclear.c

OBJS = $(SRCS:.c=.o)
HDRS = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

bonus:	all

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus
