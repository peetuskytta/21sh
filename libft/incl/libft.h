/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:01:21 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/26 13:06:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/stat.h>
# include <math.h>
# include "../ft_printf/inc/print.h"
# include "../ft_printf/inc/print_internal.h"

# define BUFF_SIZE 8
# define READLINE_MAX_FD 2
# define FD_SIZE 4096

typedef struct s_list
{
	char		**arg;
	size_t		arg_size;
	size_t		elem_count;
}				t_list;

typedef struct s_bitree
{
	char			*item;
	struct s_bitree	*left;
	struct s_bitree	*right;
}				t_bitree;

/*
** arrays
*/
char				**ft_reallocarray(char **old_arr, int rows);
void				ft_arr_free(void ***arr);
char				**ft_arrnew(size_t rows, size_t row_len);
char				**ft_arrdup(char **arr);
void				ft_arrtrim(char **arr, size_t row);
int					ft_array_strcmp(int *array, char *str);
/*
** ascii
*/
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isdigit(int n);
int					ft_isascii(int n);
int					ft_isalpha(int n);
int					ft_isalnum(int n);
int					ft_is_oddnbr(int nbr);
int					ft_is_ws_without_nl(char c);
/*
** math and counting
*/
size_t				ft_abs(long int value);
float				ft_float_abs(float value);
unsigned long int	ft_long_abs(long long int value);
long long int		ft_powerof(long int nb, unsigned int p);
long long int		ft_llmax(long long x, long long y);
int					ft_max(int x, int y);
size_t				ft_wdcounter(char const *str, char c);
int					dig_count_base(long long int nb,
						long int base);
int					ft_count_digit(long int nb);
ssize_t				ft_strstr_start(const char *haystack, const char *needle);
int					ft_strchr_index(char *str, char c, char start);
void				ft_swap(int *a, int *b);
int					ft_count_chrstr(char *str, char c);
int					ft_finword_rev(char *str);
/*
** convertions
*/
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa_base(long long int nb,
						long int base);
char				*ft_lutoa_base(unsigned long long int nb,
						long int base);
char				*ft_lutoa(unsigned long int nb);
char				*ft_utoa(unsigned long int n);
char				*ft_utoa_base(unsigned long int nb, long int base);
double				ft_atof(const char *str);
char				*ft_litoa(long long int n);
char				*ft_ftoa(long double d, size_t decimal);
char				*ft_sizetoa(size_t nb);
/*
** list
** t_list				*ft_lstnew(void const *content, size_t content_size);
** t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
** void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
** void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
** void				ft_lstadd(t_list **alst, t_list *new);
** void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
*/
t_list				*ft_listnew(size_t size);
int					ft_addlstelem(t_list *lst, char *str);
void				ft_freelst(t_list *ls);
/*
** memory
*/
void				ft_free_two(char *ptr1, char *ptr2);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src,
						size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c,
						size_t n);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void				ft_bzero(void *s, size_t n);
int					ft_memdel_range(const int nbr, ...);
void				swap_char_ptr(char **first, char **second);
/*
** print
*/
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					ft_print_fd(int fd, const char *format, ...);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putlong(long int nb);
void				ft_putdouble(long double f, int decimal);
void				ft_putshort(short nb);
void				ft_print_bits(size_t nb, size_t size);
void				ft_putnbr_endl(int nb);
void				ft_putarr(char **arr);
int					get_next_line(const int fd, char **line);
/*
** string manipulation
*/
char				*ft_charstr(char c);
void				ft_strcpyrev(char *cmd, char *rev, int max, int n);
char				*ft_strtrim(char const *s);
char				*ft_strctrim(char const *s, char c);
char				*ft_strtrim_top(const char *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcnew(size_t size, char c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, size_t flag);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strstr_end(const char *haystack, const char *needle);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *stack, const char *ndle, size_t i);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
int					ft_strilen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strtrim_end(const char *s, char c);
char				*ft_strrev(char *str);
char				*ft_strcdup(char *str, char c);
char				*ft_strtrimdup(char *str);
int					chrcpy_str_rev(char *cmd, char *rev, int max, int n);
/*
** binary trees
*/
t_bitree			*ft_new_node(char *item);
void				ft_add_node(t_bitree **root, t_bitree *node);
int					ft_tree_height(t_bitree *root);
/*
** bits
*/
size_t				ft_orfill_bit(size_t nb, size_t *arr);
size_t				ft_oradd_bit(size_t nb, size_t arr);
/*
** permissions
*/
int					ft_is_directory(char *filename);

#endif
