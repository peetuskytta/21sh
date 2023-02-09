/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:40:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/06 10:29:17 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "shell.h"

# define HIST_FILE "/tmp/.21sh_history"

void	history_runtime(t_shell *shell);
void	history_reset(t_shell *shell, t_win *window);
void	history_create(char **history);
void	history_fetch(t_shell *shell);
void	history_traverse(t_shell *shell, t_win *win, int *idx, int key);

#endif
