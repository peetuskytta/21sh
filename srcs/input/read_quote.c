/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:49:29 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 14:00:59 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Returns the character of the quote that is open.
*/
static void	identify_open_quote(t_shell *shell)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (shell->q_input[i] != '\0')
	{
		if ((shell->q_input[i] == D_QUOTE || shell->q_input[i] == S_QUOTE)
			&& quote == 0)
		{
			shell->quote = shell->q_input[i];
			quote = 1;
		}
		else if (shell->q_input[i] == shell->quote && quote == 1)
		{
			shell->quote = EOF;
			quote = 0;
		}
		i++;
	}
}

/*
**	Quote handling "driver function" which identifies the open quote
**	and moves to read until new quote is found.
*/
void	read_quote(t_shell *shell)
{
	if (ft_strchr(shell->q_input, D_QUOTE)
		|| ft_strchr(shell->q_input, S_QUOTE))
		identify_open_quote(shell);
}
