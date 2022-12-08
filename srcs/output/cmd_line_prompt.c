/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:03:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/08 11:12:01 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_prompt(int quote)
{
	if (quote == S_QUOTE)
		ft_print_fd(STDOUT_FILENO, "\nquote> ");
	else if (quote == D_QUOTE)
		ft_print_fd(STDOUT_FILENO, "\ndquote> ");
	else
		ft_print_fd(STDOUT_FILENO, "\n$> ");
}
