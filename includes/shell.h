/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 13:05:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "structs.h"
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>

// # define EOF '\0'
# define HIST_FILE ".shell_history"

# define TRUE 1
# define FALSE 0
# define BUFFER 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define MAX_BUFF 4096

# include "cursor.h"
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
