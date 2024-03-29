/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rev_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:52:24 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 14:17:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_rev_cmd(t_shell *shell)
{
	int	i;

	i = ft_strlen(shell->rev_cmd);
	while (i >= 0)
		stdin_char(shell->rev_cmd[i--]);
}
