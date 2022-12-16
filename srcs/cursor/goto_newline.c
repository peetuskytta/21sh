/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/16 14:21:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_newline(t_shell *shell)
{
		tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, stdin_char);
		tputs(tgetstr("cd", NULL), 1, stdin_char);
		// tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, stdin_char);
		// tputs(tgetstr("cd", NULL), 1, stdin_char);
		read_quote(shell);
}
