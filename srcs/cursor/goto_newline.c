/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/11 23:41:14 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_newline(t_shell *shell)
{
		tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, stdin_char);
		tputs(tgetstr("cd", NULL), 1, stdin_char);
		tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, stdin_char);
		tputs(tgetstr("cd", NULL), 1, stdin_char);
		read_quote(shell);
		shell->end = 1;
		cmd_line_prompt(shell->quote);
}
