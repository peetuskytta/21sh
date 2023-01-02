/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:19:09 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 15:47:39 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"
# include "structs.h"

void	tree_execute(t_ast **tree, t_shell *shell);
void	branch_execute(t_ast *branch, t_shell *shell);
void	cmd_redir_execute(t_exec data, char **path, char **env_cpy);
void	cmd_simple_execute(t_exec data, char **path, char **env_cpy);

# endif
