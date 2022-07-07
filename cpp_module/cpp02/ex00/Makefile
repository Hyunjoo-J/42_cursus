# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 02:22:10 by hyunjoo           #+#    #+#              #
#    Updated: 2022/07/08 02:43:11 by hyunjoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fixed

CXX := c++

SRCS := main.cpp Fixed.cpp

OBJS := $(SRCS:.cpp=.o)

INCS := Fixed.hpp

RM := rm -rf

DEBUG := 0

ifeq ($(DEBUG), 1)
	CXXFLAGS 	:=	-std=c++98 -g
else
	CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror
endif

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.PHONY : debug
debug : fclean
	make DEBUG=1 all

%.o					:		%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY			:		clean
clean				:
	$(RM) $(OBJS)

.PHONY			:		fclean
fclean			:		clean
	$(RM) $(NAME)

.PHONY			:		re
re					:
	make fclean
	make all