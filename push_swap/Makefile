# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
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
=======
#    By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 17:07:42 by hyjeong           #+#    #+#              #
#    Updated: 2022/04/16 17:24:05 by hyjeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SORTER =	./srcs/sorter/main.c \
				./srcs/sorter/short_suites.c \
				./srcs/sorter/step1_target_index.c \
				./srcs/sorter/step2_keep_push.c \
				./srcs/sorter/step3_find_shortest_action.c \
				./srcs/sorter/step4_sort.c \

SRCS_COMMON =	./srcs/common/stack_utils0.c \
				./srcs/common/stack_utils1.c \
				./srcs/common/stack_utils2.c \
				./srcs/common/stack_utils3.c \
				./srcs/common/utils0.c \
				./srcs/common/push_stack.c \
				./srcs/common/reverse_rotate_stack.c \
				./srcs/common/rotate_stack.c \
				./srcs/common/swap_stack.c \
				./srcs/common/parsing_utils.c \
				./srcs/common/exit.c \


OBJS_SORTER =	${SRCS_SORTER:.c=.o}
OBJS_COMMON =	${SRCS_COMMON:.c=.o}

INCLUDE = 		./srcs/include

NAME =			push_swap

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS_COMMON} ${OBJS_SORTER}
			${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME} ${OBJS_COMMON} ${OBJS_SORTER}

clean:
			${RM} ${OBJS_COMMON} ${OBJS_CHECKER} ${OBJS_SORTER}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		checker bonus all clean fclean re
>>>>>>> 68a3d98e2905d1367baf38962dc4fe25d21fc091
