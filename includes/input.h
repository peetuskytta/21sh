/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:34:24 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/18 17:07:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "shell.h"
# include "structs.h"

/*
** READ_INPUT
*/
void	cmd_line_reprint(t_shell *shell, t_win *window);
void	cmd_line_check_row(t_shell *shell, t_win *window);
void	read_quote(t_shell *shell);
void	cmd_line(t_shell *shell, t_win *window, char c);
void	input_read(t_shell *shell);
void	input_rev_cmd(t_shell *shell);
void	input_midline(t_shell *shell, t_win *window);

#endif
