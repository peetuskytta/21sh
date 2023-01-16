/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:19:09 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/16 15:49:29 by pskytta          ###   ########.fr       */
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
void	exec_cmd(t_exec data, char *bin_path, char **env_cpy, int *output);
void	exec_clear_data(t_exec *data, char *path);

typedef enum e_pipe_fd
{
	PIPE_READ,
	PIPE_WRITE,
	PIPE_FIRST,
	PIPE_LAST,
}			t_pipe_fd;

#endif
