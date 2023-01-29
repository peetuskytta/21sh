/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:50:18 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/29 18:11:43 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	grep_coordinates(t_win *window, char *buf)
{
	int	i;
	int	x;
	int	y;

	i = 2;
	x = 0;
	y = 0;
	if (buf[0] != ESC)
		return ;
	while (buf[i] != ';')
	{
		y = (y * 10) + buf[i] - '0';
		i++;
	}
	while (buf[i] != 'R')
	{
		x = (x * 10) + buf[i] - '0';
		i++;
	}
	window->current_row = y;
	window->loc = x;
}

void	cursor_find(t_shell *shell, t_win *window)
{
	char	buf[MAX_BUFF + 1];

	if (enable_rawmode(shell) == 0)
		ft_perror("Error with tcgetattr\n");
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
	ft_putstr_fd("\x1B[6n", STDOUT_FILENO);
	ft_memset(buf, 0, sizeof(char) * (MAX_BUFF + 1));
	if (read(STDIN_FILENO, &buf, MAX_BUFF) > 0)
		grep_coordinates(window, buf);
	window->loc = shell->prmpt_len;
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
	ft_memset(buf, 0, sizeof(char) * (MAX_BUFF + 1));
}
