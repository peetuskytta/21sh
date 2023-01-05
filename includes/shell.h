/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 10:57:33 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "structs.h"
# include <stdbool.h>
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <sys/wait.h>

# define NL ft_putchar('\n')
# define DB ft_putstr("\nYOU ARE HERE\n")
# define NULL_BYTE '\0'
# define TRUE 1
# define FALSE 0
# define BUFFER 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define MAX_BUFF 4096

# include "ast.h"
# include "buildin.h"
# include "cursor.h"
# include "errors.h"
# include "execute.h"
# include "history.h"
# include "initialise.h"
# include "input.h"
# include "keys.h"
# include "output.h"
# include "panic.h"
# include "parse.h"
# include "rawmode.h"
# include "redirection.h"

/*
** SHELL
*/
int		env_variable_counter(char **environ);
void	allocation_check(void **check);

#endif
