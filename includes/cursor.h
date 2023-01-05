/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:22:12 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 10:53:32 by zraunio          ###   ########.fr       */
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
void	cursor_find(t_win *window);
void	cursor_load(t_shell *shell, int x, int y);
void	cursor_change_row(t_shell *shell, t_win *window, int key);
void	goto_newline(t_shell *shell, t_win *window);
void	goto_end(t_shell *shell, t_win *window, int key);
int		goto_sides(t_shell *shell, t_win *window, int key);
void	goto_word(t_shell *shell, t_win *window, int ws, int key);

#endif
