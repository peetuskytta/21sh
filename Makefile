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
OUTPUT_DIR = srcs/output
KEYS_DIR = srcs/keys
PANIC_DIR = srcs/panic
PARSE_DIR = srcs/parse
RAWMODE_DIR = srcs/rawmode

#Sources by folder
_SRCS := $(addprefix $(SRCS_DIR)/, main.c \
								allocation_check.c \
								env_variable_counter.c)

_CURSOR := $(addprefix $(CURSOR_DIR)/, init_window.c \
									goto_newline.c)

_EXECUTE := $(addprefix $(EXECUTE_DIR)/,)

_INIT := $(addprefix $(INIT_DIR)/, init_shell.c)

_INPUT := $(addprefix $(INPUT_DIR)/, read_quote.c \
								cmd_line.c\
								read_stdin.c)

_KEYS := $(addprefix $(KEYS_DIR)/, ft_iscntrl.c \
								keypress.c \
								read_key.c \
								special_keys.c)

_OUTPUT := $(addprefix $(OUTPUT_DIR)/, stdin_char.c \
									cmd_line_prompt.c)

_PANIC := $(addprefix $(PANIC_DIR)/, ft_strerror.c \
									ft_perror.c \
									ft_abort.c)

_PARSE:= $(addprefix $(PARSE_DIR)/, lexer.c)

_RAWMODE := $(addprefix $(RAWMODE_DIR)/, enable_rawmode.c \
										kill_mode.c)

#All to object files
ALL_SRCS := $(_SRCS) $(_CURSOR) $(_EXECUTE) $(_INIT) $(_INPUT) $(_KEYS) $(_OUTPUT) $(_PANIC) $(_PARSE) $(_RAWMODE)
OBJ := *.o
# $(_SRCS:.c=.o) $(_CURSOR:.c=.o) $(_EXECUTE:.c=.o) $(_INIT:.c=.o) $(_INPUT:.c=.o) $(_KEYS:.c=.o) $(_OUTPUT:.c=.o) $(_PANIC:.c=.o) $(_PARSE:.c=.o) $(_RAWMODE:.c=.o)
#libft
LIBFT_M := make -s -C srcs/libft
LIBFT_A := libft/libft.a
HEADER := includes/shell.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@echo "$(BOLD)$(WHITE)$(NAME) Compilation done$(RESET)"
	@$(CC) $(FLAGS_DB) $(OBJ) $(LIBFT_A) -ltermcap -o $(NAME)

$(OBJ):
	@ $(CC) $(FLAGS_DB) -c $(ALL_SRCS) -I includes/

$(LIBFT_A):
	@make -C libft/

rori:
	@make re -C libft
	@ $(CC) $(FLAGS) $(_KEYS) $(_RAWMODE) $(_CURSOR) $(_PANIC) $(_OUTPUT) $(LIBFT_A) -ltermcap -I includes/

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@find . -type f -name '*.o' -print -delete -o -name '#*#' -print -delete
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@find . -type f -name '.DS_Store' -print -delete
	@echo "$(BOLD)$(RED)OBJ deleted$(RESET)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
