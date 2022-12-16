/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:37:03 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/13 15:00:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef OUTPUT_H
# define OUTPUT_H
# include "shell.h"
# include "structs.h"

/*
** OUTPUT
*/
int		stdin_char(int c);
void	cmd_line_prompt(int quote);
void	cmd_line_stdin(t_shell *shell);

# endif
