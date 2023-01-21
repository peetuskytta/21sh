/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_nl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:42:02 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/20 17:16:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	ft_error_nl(t_shell *shell, char *err)
{
	ft_print_fd(STDERR_FILENO, "\033[0;31m\n%s\033[0m", err);
	shell->end = 1;
	shell->quote = EOF;
}
