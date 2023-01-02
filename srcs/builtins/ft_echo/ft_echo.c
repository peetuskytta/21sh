/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:08:12 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/02 16:13:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

/*
**	Builtin function to print the tokens after "echo" command
*/
int	ft_echo(char **args, bool n_fl)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		ft_putstr(args[i++]);
		ft_putchar(' ');
	}
	if (n_fl == FALSE)
		ft_putchar('\n');
	return (TRUE);
}
