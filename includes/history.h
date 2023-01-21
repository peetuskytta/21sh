/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:40:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 15:59:59 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "shell.h"

# define HIST_FILE ".21sh_history"

void	history(t_shell *shell);
void	history_runtime(t_shell *shell);
void	history_reset(t_shell *shell, t_win *window);
void	history_create(char **history);
void	history_fetch(t_shell *shell);
void	history_traverse(t_shell *shell, t_win *win, int *idx, int key);
void	history_init(t_shell *shell);

#endif
