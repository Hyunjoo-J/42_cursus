# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 03:05:03 by hyunjoo           #+#    #+#              #
#    Updated: 2022/07/01 03:05:38 by hyunjoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS = src/Phonebook.cpp src/Contact.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
COMPILER = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(FLAGS) $^ -o $@

.cpp.o :
	$(COMPILER) $(FLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all