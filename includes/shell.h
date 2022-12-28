/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/28 16:06:21 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "structs.h"
# include "parse.h"
# include "ast.h"
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>

# define NL ft_putchar('\n')
# define DB ft_putstr("\nYOU ARE HERE\n")
# define NULL_BYTE '\0'
# define TRUE 1
# define FALSE 0
# define BUFFER 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define MAX_BUFF 4096

# include "cursor.h"
# include "history.h"
# include "keys.h"
# include "errors.h"
# include "parse.h"
# include "buildin.h"
# include "initialise.h"
# include "input.h"
# include "panic.h"
# include "rawmode.h"
# include "output.h"

/*
** SHELL
*/
int		env_variable_counter(char **environ);
void	allocation_check(void **check);

# endif
