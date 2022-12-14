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
SRCS_DIR = srcs/
AST_DIR = srcs/ast/
CURSOR_DIR = srcs/cursor/
EXECUTE_DIR = srcs/execute/
HISTORY_DIR = srcs/history/
INIT_DIR = srcs/init/
INPUT_DIR = srcs/input/
OUTPUT_DIR = srcs/output/
KEYS_DIR = srcs/keys/
PANIC_DIR = srcs/panic/
PARSE_DIR = srcs/parse/
RAWMODE_DIR = srcs/rawmode/
REDIRECTION_DIR = srcs/redirection/
OBJS_DIR = obj/
INCL = -I includes/

#Sources by folder
_AST := ast_constructor.c \
		ast_consume_tokens.c \
		ast_set_redir.c \
		ast_print.c \
		ast_release.c \

_SRCS :=  main.c \
		allocation_check.c \
		env_variable_counter.c

_CURSOR := cursor_reset_line.c \
		cursor_change_row.c \
		cursor_row_idx.c \
		cursor_load.c \
		cursor_find.c \
		goto_newline.c \
		goto_sides.c \
		goto_word.c \
		goto_end.c

_EXECUTE := exec_tree.c \
		exec_branch.c \
		exec_cmd.c \
		exec_binary_check.c \
		exec_find_binary.c \
		exec_fetch_path_var.c \
		exec_clear_data.c

_INIT := init_shell.c \
		init_window.c \
		init_prompt.c \
		init_term.c \
		init_row_idx.c \
		init_in_out_err.c

_INPUT := read_quote.c \
		cmd_line.c \
		cmd_line_reprint.c \
		input_read.c \
		input_rev_cmd.c \
		input_row_len.c

_HISTORY := history_create.c \
		history_traverse.c \
		history_fetch.c \
		history_runtime.c \
		history.c

_KEYS := key_listen.c \
		read_key.c \
		special_keys.c \
		key_is_ctrl_alpha.c

_OUTPUT := stdin_char.c \
		cmd_line_prompt.c

_PANIC := ft_strerror.c \
		ft_perror.c \
		ft_abort.c

_PARSE:= token_list_build.c \
		token_list_free.c \
		parser.c

_RAWMODE := enable_rawmode.c \
		kill_mode.c

_REDIRECTION := redirection_loop.c \
		redir_file_check.c \
		redir_folder_check.c

#All to object files
ALL_SRCS :=	$(addprefix $(SRCS_AST), $(_AST)) \
			$(addprefix $(SRCS_DIR), $(_SRCS)) \
			$(addprefix $(CURSOR_DIR), $(_CURSOR)) \
			$(addprefix $(HISTORY_DIR), $(_HISTORY)) \
			$(addprefix $(EXECUTE_DIR), $(_EXECUTE)) \
			$(addprefix $(INIT_DIR), $(_INIT)) \
			$(addprefix $(INPUT_DIR), $(_INPUT)) \
			$(addprefix $(KEYS_DIR), $(_KEYS)) \
			$(addprefix $(OUTPUT_DIR), $(_OUTPUT)) \
			$(addprefix $(PANIC_DIR), $(_PANIC)) \
			$(addprefix $(PARSE_DIR), $(_PARSE)) \
			$(addprefix $(RAWMODE_DIR), $(_RAWMODE)) \
			$(addprefix $(REDIRECTION_DIR), $(_REDIRECTION))

SRCS = $(_SRCS) $(_CURSOR) $(_INIT) $(_INPUT) $(_KEYS) \
$(_OUTPUT) $(_PANIC) $(_PARSE) $(_RAWMODE) $(_HISTORY) $(_AST) $(_EXECUTE) $(_REDIRECTION)
OBJ_FILES = $(SRCS:.c=.o)
OBJS = $(patsubst %, $(OBJS_DIR)%, $(SRCS:.c=.o))
#libft
LIBFT_M := make -s -C srcs/libft
LIBFT_A := libft/libft.a
HEADER := includes/shell.h

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@$(CC) $(FLAGS_DB) $(OBJS) -o $(NAME) -ltermcap -L ./libft -lft >> makelog.txt
	@echo "$(BOLD)$(WHITE)----------$(NAME) COMPILATION DONE----------$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR) >> makelog.txt

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(AST_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(CURSOR_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(HISTORY_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(INIT_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(INPUT_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(KEYS_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(OUTPUT_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(PANIC_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(PARSE_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(RAWMODE_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(EXECUTE_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(OBJS_DIR)%.o: $(REDIRECTION_DIR)%.c
	@$(CC) $(FLAGS_DB) $(INCL) -c $< -o $@ >> makelog.txt

$(LIBFT_A):
	-@make -C libft/ >> makelog.txt

clean:
	-@make -C libft clean >> makelog.txt
	-@rm -f $(OBJS) >> makelog.txt
	@find . -type f -name '*.o' -print -delete -o -name '#*#' -print -delete >> makelog.txt
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete >> makelog.txt
	@find . -type f -name '.DS_Store' -print -delete >> makelog.txt
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
