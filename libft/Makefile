NAME = libft.a

FT_PRINTF = libftprintf.a

CC = gcc
RED = \033[31m
WHITE = \033[37m
RESET = \033[0m
RED = \033[31m
BOLD = \033[1m
GREEN = \\n\033[32;1m

CFLAGS = -Wall -Wextra -Werror -I$(HDR_SRC)

# ASCII_DIR = ./ascii/
# CONV_DIR = ./convert/
# LIST_DIR = ./list/
# MATH_DIR = ./math/
# MEM_DIR = ./mem/
# PRINT_DIR = ./print/
# PRINTF_DIR = ./ft_printf/
# STR_DIR = ./src/
# BIT_DIR = ./bits

# ASCII = $(addprefix $(ASCII_DIR), $(_ASCII_SRC))
# CONV = $(addprefix $(CONV_DIR), $(_CONV_SRC))
# LIST = $(addprefix $(LIST_DIR), $(_LIST_SRC))
# MATH = $(addprefix $(MATH_DIR, $(_MATH_SRC))
# MEM = $(addprefix $(MEM_DIR, $(_MEM_SRC))
# PRINT = $(addprefix $(PRINT_DIR), $(_PRINT_SRC))
# STR = $(addprefix $(STR_DIR), $(_STR_SRC))

_ARRAY_SRC = array/ft_arrdup.c \
			array/ft_arrfree.c \
			array/ft_arrnew.c \
			array/ft_reallocarray.c \
			array/ft_arrtrim.c \
			array/ft_array_strcmp.c

_ASCII_SRC =  ascii/ft_isalnum.c \
		ascii/ft_isalpha.c \
		ascii/ft_isascii.c \
		ascii/ft_isprint.c \
		ascii/ft_ispunct.c \
		ascii/ft_isdigit.c \
		ascii/ft_isspace.c \
		ascii/ft_is_oddnbr.c \
		ascii/ft_is_ws_without_nl.c

_CONV_SRC = convert/ft_atoi.c \
		convert/ft_itoa_base.c \
		convert/ft_itoa.c \
		convert/ft_lutoa_base.c \
		convert/ft_lutoa.c \
		convert/ft_tolower.c \
		convert/ft_toupper.c \
		convert/ft_utoa_base.c \
		convert/ft_utoa.c \
		convert/ft_atof.c \
		convert/ft_litoa.c \
		convert/ft_ftoa.c \
		convert/ft_sizetoa.c

_LIST_SRC = list/ft_listnew.c \
			list/ft_addlstelem.c \
			list/ft_freelst.c

_MATH_SRC = math/dig_count_base.c \
		math/dig_count.c \
		math/ft_abs.c \
		math/ft_float_abs.c \
		math/ft_llmax.c \
		math/ft_max.c \
		math/ft_wdcounter.c \
		math/ft_powerof.c \
		math/ft_strstr_start.c \
		math/ft_findword_rev.c \
		math/ft_strchr_index.c \
		math/ft_count_chrstr.c \
		math/ft_long_abs.c \
		math/ft_swap.c \

_MEM_SRC =  mem/ft_bzero.c \
		mem/ft_memalloc.c \
		mem/ft_memccpy.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memdel.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		mem/ft_realloc.c \
		mem/ft_memdel_range.c \
		mem/swap_char_ptr.c

_PERMISSIONS_SRC = permissions/ft_is_directory.c

_PRINT_SRC = print/ft_putchar_fd.c \
		print/ft_putchar.c \
		print/ft_putendl_fd.c \
		print/ft_putendl.c \
		print/ft_putnbr_fd.c \
		print/ft_putnbr.c \
		print/ft_putstr_fd.c \
		print/ft_putstr.c \
		print/ft_putlong.c \
		print/ft_putdouble.c \
		print/ft_putshort.c \
		print/ft_print_bits.c \
		print/ft_putarr.c \
		print/ft_putnbr_endl.c \
		print/get_next_line.c

_BIT_SRC = bits/ft_oradd_bit.c \
		bits/ft_orfill_bit.c

_STR_SRC = str/ft_charstr.c \
		str/ft_strcat.c \
		str/ft_strchr.c \
		str/ft_strclr.c \
		str/ft_strcmp.c \
		str/ft_strcpy.c \
		str/ft_strctrim.c \
		str/ft_strdel.c \
		str/ft_strdup.c \
		str/ft_strndup.c \
		str/ft_strequ.c \
		str/ft_striter.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strjoin_free.c \
		str/ft_strlcat.c \
		str/ft_strlen.c \
		str/ft_strilen.c \
		str/ft_strmap.c \
		str/ft_strmapi.c \
		str/ft_strncpy.c \
		str/ft_strncat.c \
		str/ft_strmapi.c \
		str/ft_strncat.c \
		str/ft_strncmp.c \
		str/ft_strnequ.c \
		str/ft_strnew.c \
		str/ft_strcnew.c \
		str/ft_strnstr.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strsplit.c \
		str/ft_strstr.c \
		str/ft_strsub.c \
		str/ft_strtrim.c \
		str/ft_strtrim_top.c \
		str/ft_strtrim_end.c \
		str/ft_strrev.c \
		str/ft_strstr_end.c \
		str/ft_strcdup.c \
		str/ft_strtrimdup.c \
		str/ft_strcpyrev.c \
		str/chrcpy_str_rev.c

_TREE_SRC = trees/ft_add_node.c \
		trees/ft_new_node.c

OBJ = $(LIBFT_OBJ)
OBJ_DIR = obj
LIBFT_SRCS = $(_ARRAY_SRC) $(_PERMISSIONS_SRC) $(_STR_SRC) $(_PRINT_SRC) $(_MEM_SRC) $(_MATH_SRC) $(_LIST_SRC) $(_CONV_SRC) $(_ASCII_SRC) $(_TREE_SRC) $(_BIT_SRC)
LIBFT_OBJ = $(_ARRAY_SRC:.c=.o) $(_PERMISSIONS_SRC:.c=.o) $(_ASCII_SRC:.c=.o) $(_CONV_SRC:.c=.o) $(_LIST_SRC:.c=.o) $(_MATH_SRC:.c=.o) $(_MEM_SRC:.c=.o) $(_PRINT_SRC:.c=.o) $(_STR_SRC:.c=.o) $(_BIT_SRC:.c=.o) $(_TREE_SRC:.c=.o)
PRINTF_OBJ = ft_printf/obj/*.o ft_printf/obj/sub/*.o

HDR_SRC= ./incl

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "$(GREEN)$(BOLD)LIBFT DONE$(RESET)"
	-@make -C ft_printf
	-@ $(CC) $(CFLAGS) -c $(LIBFT_SRCS)
	-@mv *.o $(OBJ_DIR)
	-@ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	-@make clean -C ft_printf
	-@rm -f $(OBJS)
	-@rm -f $(LIBFT_OBJ)
	-@find . -type f -name '*.o' -print -delete -o -name '#*#' -print -delete
	-@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	-@find . -type f -name '.DS_Store' -print -delete
	@echo "$(RED)$(BOLD)LIBFT OBJ DELETED$(RESET)"

fclean: clean
	-@rm -f $(NAME)
	-@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)LIBFT REST OF STUFFS DELETED $(RESET)"

re: fclean all

.SILENT: clean fclean re

.PHONY: all clean fclean re
