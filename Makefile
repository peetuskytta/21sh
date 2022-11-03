#Compiler and compiler flags
CC := gcc
#FLAGS := -Wall -Wextra -Werror -g -fsanitize=address
FLAGS := -Wall -Wextra -Werror

#Color scheme
WHITE = \033[37m
RESET = \033[0m
RED = \033[31m
BOLD = \033[1m

#Target Binary Program
NAME := 21sh

SOURCES := srcs/main.c \
	srcs/allocation_check.c \
	srcs/env_variable_counter.c \
	srcs/init_shell.c \
	srcs/read_input.c \
	srcs/read_quote.c \
	srcs/lexer.c \

OBJ := $(SOURCES:.c=.o)

LIBFT_M := make -s -C srcs/libft
LIBFT_A := libft/libft.a
HEADER := includes/shell.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@echo "$(BOLD)$(WHITE)$(NAME) Compilation done$(RESET)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I includes/

$(LIBFT_A):
	@make -C libft/

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "$(BOLD)$(RED)OBJ deleted$(RESET)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re