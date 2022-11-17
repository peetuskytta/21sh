/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:01:43 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/15 08:02:47 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	ft_putchar_out(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

static char	read_key(t_shell *shell)
{
	int		i;
	char	c;

	i = read(STDIN_FILENO, &c, 1);
	while (i != 1)
	{
		if (i == -1)
			kill_mode("read", shell);
		i = read(STDIN_FILENO, &c, 1);
	}
	return (c);
}

void	keypress(t_shell *shell)
{
	char	c;

	c = read_key(shell);
	while (c)
	{
		if (c == CTRL_C)
			kill_mode("exit", shell);
		else if (ft_isprint(c) || (ft_isspace(c)))
		{
			if (c == ENTER)
				tputs(tgetstr("cr", NULL), 1, ft_putchar_out);
			write(STDOUT_FILENO, &c, 1);
		}
		c = read_key(shell);
	}
}
