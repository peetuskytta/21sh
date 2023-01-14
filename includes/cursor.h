/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:22:12 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 13:40:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H
# include "structs.h"
# include "shell.h"

/*
** CURSOR
*/
void	goto_newline(t_shell *shell, t_win *window);
void	cursor_reset_line(t_win *window, int len);
void	cursor_find(t_shell *shell, t_win *window);
void	cursor_load(t_win *window, int y);
void	cursor_goto_sides(t_shell *shell, t_win *window, int key);
void	cursor_goto_end(t_shell *shell, t_win *window, int key);
int		cursor_move(t_shell *shell, t_win *win, int len, int key);
/* 
** void	cursor_row_col(t_shell *shell, t_win *window);
** void	goto_word(t_shell *shell, t_win *window, int ws, int key);
*/

#endif
