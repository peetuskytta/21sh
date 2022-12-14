/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:40:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/14 15:24:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HISTORY_H
# define HISTORY_H
# include "shell.h"

# define HISTORY "~/.21sh_history"

void	history(t_shell *shell);
void	history_runtime(t_shell *shell);

# endif
