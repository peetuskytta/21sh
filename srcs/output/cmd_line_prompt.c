/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:03:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/08 10:00:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_prompt(int quote)
{
	if (quote == CHAR_QUOTE)
		ft_print_fd(STDOUT_FILENO, "\nquote> ");
	else if (quote == CHAR_DQUOTE)
		ft_print_fd(STDOUT_FILENO, "\ndquote> ");
	else
		ft_print_fd(STDOUT_FILENO, "\n$> ");
}
