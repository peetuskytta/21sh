/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:40:37 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/28 15:47:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_prompt(t_shell *shell)
{
	if (shell->quote == D_QUOTE)
		shell->prmpt_len = 9;
	else if (shell->quote == S_QUOTE)
		shell->quote = 8;
	else
		shell->quote = 3;
}