# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 01:56:46 by hyunjoo           #+#    #+#              #
#    Updated: 2022/02/25 03:35:08 by hyunjoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_B = server_bonus
CLIENT_B = client_bonus

LIBFT = ./libft/libft.a

HEADER_S = server.h
HEADER_C =client.h

HEADER_SB = server_bonus.h
HEADER_CB = client_bonus.h

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(CLIENT) $(SERVER) $(HEADER_S) $(HEADER_C)

$(SERVER): server.c $(HEADER_S)
	@gcc server.c $(LIBFT) -o $@
	@echo $@ ready

$(CLIENT): client.c $(HEADER_C)
	@gcc $(CFLAGS) client.c $(LIBFT) -o $@
	@echo $@ ready

$(SERVER_B): server_bonus.c $(HEADER_SB)
	@gcc server_bonus.c $(LIBFT) -o $@
	@echo $@ ready
$(CLIENT_B): client_bonus.c $(HEADER_B)
	@gcc client_bonus.c $(LIBFT) -o $@
	@echo $@ ready

$(LIBFT):
	@make -C./libft
bonus: $(LIBFT) $(SERVER_SB) $(SERVER_B) $(CLIENT_B) $(HEADER_CB) $(HEADER_SB)

clean:
	@make clean -C ./libft

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	make fclean -C ./libft

re: fclean all

.PHONY: all re clean fclean bonus