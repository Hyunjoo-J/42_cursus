CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = philo_bonus

SRCS = philo_bonus.c check_args_bonus.c utils_bonus.c end_program_bonus.c data_fill_bonus.c monitor_bonus.c print_bonus.c check_death_bonus.c
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