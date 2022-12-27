/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:22:12 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/27 15:46:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURSOR_H
# define CURSOR_H
# include "structs.h"
# include "shell.h"

/*
** CURSOR
*/
void	init_window(t_win *window);
void	goto_newline(t_shell *shell, t_win *window);
int		goto_sides(t_shell *shell, t_win *window, int key);
void	goto_position(t_shell *shell, t_win *window, int ws, int key);

#endif
