/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:34:24 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/04 14:47:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INPUT_H
# define INPUT_H
# include "shell.h"
# include "structs.h"

/*
** READ_INPUT
*/
void	cmd_line_reprint(t_shell *shell, t_win *window, char c);
void	read_quote(t_shell *shell);
void	cmd_line(t_shell *shell, char c);
void	input_read(t_shell *shell);
void	input_rev_cmd(t_shell *shell);
void	input_row_len(t_shell *shell, t_win *window);

#endif
