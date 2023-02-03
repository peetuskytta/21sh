/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:40:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/03 13:36:46 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "shell.h"

# define HIST_FILE "/tmp/.21sh_history"

void	history(t_shell *shell);
void	history_runtime(t_shell *shell);
void	history_reset(t_shell *shell, t_win *window);
void	history_create(char **history);
void	history_fetch(t_shell *shell);
void	history_traverse(t_shell *shell, t_win *win, int *idx, int key);
void	history_init(t_shell *shell);

#endif
