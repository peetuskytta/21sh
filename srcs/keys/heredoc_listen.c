/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_listen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:50:05 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/03 17:07:37 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_delim(t_herfd *shell)
{
	int		i;
	char	*temp;

	i = ft_strstr_rev(shell->input, shell->delim);
	if (i != -1 && shell->input[ft_strilen(shell->input) - \
	ft_strilen(shell->delim) - 2] == '\n')
	{
		temp = ft_strsub(shell->input, 0, ft_strlen(shell->input) - \
			ft_strilen(shell->delim) - 1);
		ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
		shell->input = ft_strcpy(shell->input, temp);
		ft_memdel((void *)&temp);
		return (1);
	}
	return (0);
}

static int	keys_heredoc(char *input, int *i)
{
	if (input[0] == 27)
	{
		while (input[*i] != '\0')
			*i += 1;
		return (1);
	}
	else if (input[0] == ENTER)
		return (ENTER);
	else
		return (0);
}

static void	save_to_heredoc(t_herfd *shell, char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	shell->input[shell->idx] = c;
	shell->idx++;
}

int	heredoc_listen(t_herfd *shell, char *input, int i)
{
	int	key;

	while (input[i] != '\0')
	{
		key = keys_heredoc(input, &i);
		if (key == ENTER || shell->idx + 1 > MAX_BUFF
			|| (input[i] == CTRL_D && shell->input[shell->idx - 1] == '\n'))
		{
			if (input[i] != CTRL_D)
				save_to_heredoc(shell, '\n');
			if (is_delim(shell) == 1 || shell->idx + 1 >= MAX_BUFF
				|| input[i] == CTRL_D)
				return (-1);
			ft_putstr_fd("> ", STDOUT_FILENO);
		}
		else if (shell->idx + 1 < MAX_BUFF && key == 0)
		{
			if (input[i] == '\t')
				input[i] = ' ';
			save_to_heredoc(shell, input[i]);
		}
		i++;
	}
	return (1);
}
