/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:34:24 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/28 16:18:33 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INPUT_H
# define INPUT_H
# include "shell.h"
# include "structs.h"

/*
** READ_INPUT
*/
int		command_prompt_loop(t_shell *shell);
void	read_quote(t_shell *shell);
void	cmd_line(t_shell *shell, char c);
void	input_read(t_shell *shell);
void	input_rev_cmd(t_shell *shell);

#endif
