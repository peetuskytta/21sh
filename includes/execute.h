/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:19:09 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/05 16:16:56 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"

bool	exec_binary_check(char *bin_path, char *cmd);
char	*exec_find_binary(char **path, char *cmd);
char	**exec_fetch_path_var(char **env);
void	exec_tree(t_ast **tree, t_shell *shell);
void	exec_branch(t_ast *branch, t_shell *shell);
void	exec_cmd_redir(t_exec data, char **env_cpy);
void	exec_cmd_simple(t_exec data, char **env_cpy);
void	exec_clear_data(t_exec *data, char *path);

#endif
