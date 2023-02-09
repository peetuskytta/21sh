/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/06 16:55:27 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	input_validation(char *q_in)
{
	int	se;
	int	pi;
	int	i;

	i = 0;
	se = 0;
	pi = 0;
	while (q_in[i] && i < MAX_BUFF)
	{
		if (q_in[i] == CHAR_SEMICOLON)
			se++;
		if (q_in[i] == CHAR_PIPE)
			pi++;
		i++;
	}
	if (se > MAX_REDIR || pi > MAX_PIPE)
	{
		ft_memset(q_in, '\0', sizeof(char) * (MAX_BUFF * 2 + 1));
		return (-1);
	}
	return (0);
}

void	goto_newline(t_shell *shell)
{
	int	i;

	i = ft_strilen(shell->rev_cmd);
	if (i > 0)
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, i);
	i = ft_strilen(shell->q_input);
	if (i + shell->cmd_idx + 1 > MAX_BUFF * 2)
	{
		ft_error_nl(shell, CMD_TOO_LONG);
		return ;
	}
	if (i > 0)
	{
		shell->q_input[i] = '\n';
		i += 1;
	}
	ft_memcpy(&shell->q_input[i], shell->cmd_line, ft_strilen(shell->cmd_line));
	shell->flg = 1;
	if (input_validation(shell->q_input) == -1)
		ft_error_nl(shell, GEN_ARG);
	read_quote(shell);
}
