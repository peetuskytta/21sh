/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:40:37 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/20 15:38:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_prompt(t_shell *shell)
{
	if (shell->quote == D_QUOTE || shell->quote == S_QUOTE)
		shell->prmpt_len = 2;
	else
		shell->prmpt_len = 3;
}
