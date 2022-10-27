/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/27 13:46:40 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "keys.h"
#include <termios.h>

typedef struct s_shell
{
	char	**environ;
	char	**path_array;
	char	*minish;
	int		num_of_variables;
	int		quote;
	int		l_flag;
	int		p_flag;
	int		n_flag;
	int		i;
	int		x;
	int		dir_len;
	int		previous_dir_in_cd;
	char	*curr_shell;
	char	*prev_dir;
}				t_shell;

/*
** KEYS
*/
int		ft_iscntrl(char c);
void	keypress(void);

/*
** RAW
*/
void	enable_rawmode();
void	kill_mode(const char *str);

# endif
