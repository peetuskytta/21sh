/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:08:12 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 10:02:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

/*
**	Builtin function to print the tokens after "echo" command
*/
void	builtin_echo(t_shell *shell, t_exec data)
{
	int	i;

	i = 0;
	while (data.args[i] != NULL)
	{
		ft_putstr(data.args[i++]);
		ft_putchar(' ');
	}
	if (shell->flg == FALSE)
		ft_putchar('\n');
}
