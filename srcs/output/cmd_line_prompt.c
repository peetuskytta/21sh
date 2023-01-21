/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:03:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/20 15:39:11 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_prompt(int quote)
{
	if (quote == S_QUOTE || quote == D_QUOTE)
		ft_print_fd(STDOUT_FILENO, "> ");
	else
		ft_print_fd(STDOUT_FILENO, "$> ");
}
