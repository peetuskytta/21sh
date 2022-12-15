/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:40:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/15 16:14:31 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HISTORY_H
# define HISTORY_H
# include "shell.h"

# define HIST_FILE ".21sh_history"

void	history(t_shell *shell);
void	history_runtime(t_shell *shell);
void	history_create(char **history);
void	history_init(t_shell *shell);

# endif
