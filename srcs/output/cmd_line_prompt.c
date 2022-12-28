/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:03:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/19 15:13:56 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_prompt(int quote)
{
	if (quote == S_QUOTE)
		ft_print_fd(STDOUT_FILENO, "quote> ");
	else if (quote == D_QUOTE)
		ft_print_fd(STDOUT_FILENO, "dquote> ");
	else
		ft_print_fd(STDOUT_FILENO, "$> ");
}
