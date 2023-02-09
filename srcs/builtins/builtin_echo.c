/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:08:12 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/07 10:55:32 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

/*
**	Builtin function to print the tokens after "echo" command
*/
static bool	echo_flag(char *arg)
{
	if (ft_strequ("-n", arg))
		return (true);
	return (false);
}

void	builtin_echo(t_shell *shell, t_exec data)
{
	int	i;
	int	flg;

	i = 1;
	(void)shell;
	flg = echo_flag(data.args[1]);
	if (flg == true)
		i++;
	while (data.args[i] != NULL && i < 512)
	{
		ft_putstr(data.args[i]);
		i++;
		if (data.args[i])
			ft_putchar(' ');
	}
	if (flg == false)
		ft_putchar('\n');
}
