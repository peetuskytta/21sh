/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:31:07 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/12 00:00:53 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALISE_H
# define INITIALISE_H
# include "shell.h"
# include "structs.h"

/*
** INIT
*/
void	init_shell(t_shell *shell, char **environ);
void	init_term(void);
void	init_prompt(t_shell *shell);
void	init_row_idx(t_win *window);
void	init_window(t_win *window);
void	init_in_out_err(char *terminal);

#endif
