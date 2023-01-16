/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_nl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:42:02 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 12:53:29 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	ft_error_nl(t_shell *shell, t_win *window, char *err)
{
	ft_print_fd(STDERR_FILENO, "\n%s", err);
	shell->end = 1;
	shell->quote = EOF;
	goto_newline(shell, window);
}
