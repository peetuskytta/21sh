/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/26 14:38:28 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	keypress(t_shell *shell, char *read_str)
{
	int	i;

	i = 0;
	while (read_str[i] != '\0')
	{
		if (read_str[i] == CTRL_C)
		{
			kill_mode("exit", shell);
			exit (EXIT_SUCCESS);
		}
		else if (read_str[i] != '\0' && !ft_isprint(read_str[i]))
		{
			while (read_str[i] && !ft_isprint(read_str[i]))
			{
				if (read_str[i] == 9 && i > 0)
					write(STDOUT_FILENO, "\t", 1);
				ft_print_fd(STDOUT_FILENO, "%u\n", read_str[i++]);
			}
		}
		else if (ft_isprint(read_str[i]))
			stdin_char(read_str[i]);
		i++;
	}
	goto_newline(shell);
}

void	read_key(t_shell *shell)
{
	int		i;
	char	read_str[10];

	tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
	i = 0;
	while (i != 1)
	{
		ft_memset(read_str, 0, sizeof(char) * 10);
		read(STDIN_FILENO, &read_str, 10);
		if (i == -1)
			return ;
		keypress(shell, read_str);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
}
