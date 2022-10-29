/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/29 15:36:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "keys.h"
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <sys/ioctl.h>

typedef struct	s_win
{
		struct winsize	*win;
		int				cols;
		int				rows;
		int				current_row;
}				t_win;

typedef struct s_shell
{
	char	**environ;
	char	*minish;
	int		num_of_variables;
	int		quote;
	int		dir_len;
	int		previous_dir_in_cd;
	char	*prev_dir;
	t_win	*window;
}				t_shell;

/*
** CURSOR
*/
void	init_window(t_win *window);
/*
** KEYS
*/
int		ft_iscntrl(char c);
void	keypress(void);

/*
** RAW
*/
int		enable_rawmode(void);
void	kill_mode(const char *str);

# endif
