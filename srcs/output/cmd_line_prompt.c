/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:03:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/08 09:18:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_prompt(int quote)
{
	ft_putnbr_endl(6);
	if (quote == CHAR_QUOTE)
		ft_print_fd(STDOUT_FILENO, "quote>");
	else if (quote == CHAR_DQUOTE)
		ft_print_fd(STDOUT_FILENO, "dquote>");
	else
		ft_print_fd(STDOUT_FILENO, "$>");
}
