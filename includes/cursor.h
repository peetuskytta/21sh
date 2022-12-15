/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:22:12 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/13 13:59:46 by zraunio          ###   ########.fr       */
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
void	goto_newline(t_shell *shell);
int		goto_sides(t_shell *shell, t_win *window, int key);

#endif
