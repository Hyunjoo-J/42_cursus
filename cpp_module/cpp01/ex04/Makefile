# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyjeong <hyjeong@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 14:32:27 by hyjeong           #+#    #+#              #
#    Updated: 2022/07/11 15:22:36 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	replace

CXX					:=	c++

SRCS				:=	main.cpp
OBJS				:=	$(SRCS:.cpp=.o)

INCLUDES		:=

RM					:=	rm -f

DEBUG				:=	0

ifeq ($(DEBUG), 1)
	CXXFLAGS 	:=	-std=c++98 -g
else
	CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror
endif

.PHONY			:		all
all					:		$(NAME)

$(NAME)			:		$(OBJS) $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.PHONY			:		debug
debug				:		fclean
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
