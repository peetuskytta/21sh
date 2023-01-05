/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:19:09 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/05 10:53:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"

void	exec_tree(t_ast **tree, t_shell *shell);
void	exec_branch(t_ast *branch, t_shell *shell);
void	exec_cmd_redir(t_exec data, char **env_cpy);
void	exec_cmd_simple(t_exec data, char **env_cpy);
bool	exec_binary_check(char *bin_path, char *cmd);
char	*exec_binary_path(char **path, char *cmd);
char	**exec_fetch_path_var(char **env);

#endif
