#Compiler and compiler flags
CC := gcc
FLAGS_DB := -Wall -Wextra -Werror -g -fsanitize=address
FLAGS := -Wall -Wextra -Werror -O3

#Color scheme
WHITE = \033[37m
RESET = \033[0m
RED = \033[31m
BOLD = \033[1m

#Target Binary Program
NAME := 21sh

#Direcory locations
SRCS_DIR = srcs/
CURSOR_DIR = srcs/cursor/
EXECUTE_DIR = srcs/execute/
INIT_DIR = srcs/init/
INPUT_DIR = srcs/input/
OUTPUT_DIR = srcs/output/
KEYS_DIR = srcs/keys/
PANIC_DIR = srcs/panic/
PARSE_DIR = srcs/parse/
RAWMODE_DIR = srcs/rawmode/
OBJS_DIR = obj/
INCL = -I includes/

#Sources by folder
_SRCS :=  main.c \
		allocation_check.c \
		env_variable_counter.c

_CURSOR := init_window.c \
		goto_newline.c

# _EXECUTE :=

_INIT := init_shell.c

_INPUT := read_quote.c \
		cmd_line.c\
		read_stdin.c

_KEYS := ft_iscntrl.c \
		keypress.c \
		read_key.c \
		special_keys.c

_OUTPUT := stdin_char.c \
		cmd_line_prompt.c

_PANIC := ft_strerror.c \
		ft_perror.c \
		ft_abort.c

_PARSE:= lexer.c \
		token_list_free.c

_RAWMODE := enable_rawmode.c \
			kill_mode.c

#All to object files
	# $(addprefix $(EXECUTE_DIR), $(_EXECUTE))
ALL_SRCS := $(addprefix $(SRCS_DIR), $(_SRCS)) \
			$(addprefix $(CURSOR_DIR), $(_CURSOR)) \
			$(addprefix $(INIT_DIR), $(_INIT)) \
			$(addprefix $(INPUT_DIR), $(_INPUT)) \
			$(addprefix $(KEYS_DIR), $(_KEYS)) \
			$(addprefix $(OUTPUT_DIR), $(_OUTPUT)) \
			$(addprefix $(PANIC_DIR), $(_PANIC)) \
			$(addprefix $(PARSE_DIR), $(_PARSE)) \
			$(addprefix $(RAWMODE_DIR), $(_RAWMODE))

SRCS = $(_SRCS) $(_CURSOR) $(_INIT) $(_INPUT) $(_KEYS) \
$(_OUTPUT) $(_PANIC) $(_PARSE) $(_RAWMODE) # $(_EXECUTE)
OBJ_FILES = $(SRCS:.c=.o)
OBJS = $(patsubst %, $(OBJS_DIR)%, $(SRCS:.c=.o))
#libft
LIBFT_M := make -s -C srcs/libft
LIBFT_A := libft/libft.a
HEADER := includes/shell.h

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@echo "$(BOLD)$(WHITE)----------$(NAME) COMPILATION DONE----------$(RESET)"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -ltermcap -L ./libft -lft >> makelog.txt

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR) >> makelog.txt

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(CURSOR_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(INIT_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(INPUT_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(KEYS_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(OUTPUT_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(PANIC_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(PARSE_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(RAWMODE_DIR)%.c
	@$(CC) $(FLAGS) $(INCL) -c $< -o $@ >> makelog.txt

# $(OBJS_DIR)%.o: $(EXECUTE_DIR)%.c
# 	@$(CC) $(FLAGS) $(INCL) -c $< -o $@

$(LIBFT_A):
	-@make -C libft/ >> makelog.txt

clean:
	-@make -C libft clean >> makelog.txt
	-@rm -f $(OBJS) >> makelog.txt
	@find . -type f -name '*.o' -print -delete -o -name '#*#' -print -delete >> makelog.txt
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete >> makelog.txt
	@find . -type f -name '.DS_Store' -print -delete
	@echo "$(BOLD)$(RED)----------Objects deleted----------$(RESET)"

fclean: clean
	-@make -C libft fclean >> makelog.txt
	@rm -f $(NAME) >> makelog.txt
	@rm -rf $(OBJS_DIR) >> makelog.txt
	@rm -rf makelog.txt
	@echo "$(BOLD)$(RED)----------$(NAME) deleted----------$(RESET)"

re: fclean all

.SILENT: clean fclean re

.PHONY: all clean fclean re
