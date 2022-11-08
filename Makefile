#Compiler and compiler flags
CC := gcc
FLAGS_DB := -Wall -Wextra -Werror -g -fsanitize=address
FLAGS := -Wall -Wextra -Werror

#Color scheme
WHITE = \033[37m
RESET = \033[0m
RED = \033[31m
BOLD = \033[1m

#Target Binary Program
NAME := 21sh

#Direcory locations
SRCS_DIR = srcs
CURSOR_DIR = srcs/cursor
EXECUTE_DIR = srcs/execute
INIT_DIR = srcs/init
INPUT_DIR = srcs/input
KEYS_DIR = srcs/keys
PANIC_DIR = srcs/panic
PARSE_DIR = srcs/parse
RAWMODE_DIR = srcs/rawmode

#Sources by folder
_SRCS := $(addprefix $(SRCS_DIR)/, main.c \
								allocation_check.c \
								env_variable_counter.c)

_CURSOR := $(addprefix $(CURSOR_DIR)/, init_window.c )

_EXECUTE := $(addprefix $(EXECUTE_DIR)/,)

_INIT := $(addprefix $(INIT_DIR)/, init_shell.c)

_INPUT := $(addprefix $(INPUT_DIR)/, read_input.c \
								read_quote.c)

_KEYS := $(addprefix $(KEYS_DIR)/, ft_iscntrl.c \
								keypress.c)

_PANIC := $(addprefix $(PANIC_DIR)/, )

_PARSE:= $(addprefix $(PARSE_DIR)/, lexer.c)

_RAWMODE := $(addprefix $(RAWMODE_DIR)/, enable_rawmode.c \
										kill_mode.c \
										)

#All to object files
ALL_SRCS := $(_SRCS) $(_CURSOR) $(_EXECUTE) $(_INIT) $(_INPUT) $(_KEYS) $(_PANIC) $(_PARSE) $(_RAWMODE)
OBJ := $(_SRCS:.c=.o) $(_CURSOR:.c=.o) $(_EXECUTE:.c=.o) $(_INIT:.c=.o) $(_INPUT:.c=.o) $(_KEYS:.c=.o) $(_PANIC:.c=.o) $(_PARSE:.c=.o) $(_RAWMODE:.c=.o)
#libft
LIBFT_M := make -s -C srcs/libft
LIBFT_A := libft/libft.a
HEADER := includes/shell.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@echo "$(BOLD)$(WHITE)$(NAME) Compilation done$(RESET)"
	@$(CC) $(FLAGS) *.o $(LIBFT_A) -o $(NAME)

$(OBJ):
	@ $(CC) $(FLAGS) -c $(ALL_SRCS) -I includes/

$(LIBFT_A):
	@make -C libft/

clean:
	@make -C libft clean
	@rm -f *.o
	@echo "$(BOLD)$(RED)OBJ deleted$(RESET)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re