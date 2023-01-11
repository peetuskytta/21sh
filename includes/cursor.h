/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:22:12 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/11 17:28:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H
# include "structs.h"
# include "shell.h"

/*
** CURSOR
*/
void	cursor_reset_line(t_win *window, int len);
void	cursor_find(t_shell *shell, t_win *window);
void	cursor_load(t_shell *shell, t_win *win, int x, int len);
/* 
** void	cursor_row_col(t_shell *shell, t_win *window);
** void	goto_newline(t_shell *shell, t_win *window);
** void	goto_end(t_shell *shell, t_win *window, int key);
** int		goto_sides(t_shell *shell, t_win *window, int key);
** void	goto_word(t_shell *shell, t_win *window, int ws, int key);
*/

#endif
