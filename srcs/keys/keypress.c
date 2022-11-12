/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/12 18:56:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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
	while (c != ENTER)
	{
		if (c == CTRL_C)
			kill_mode("exit", shell);
		else if (ft_isprint(c))
			break ;
		c = read_key(shell);
	}
	goto_newline(shell);
}
