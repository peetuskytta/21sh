/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:19:09 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 11:13:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"

bool	exec_binary_check(char **bin_path, t_exec data);
char	*exec_find_binary(char **path, char *cmd);
char	**exec_fetch_path_var(char **env);
void	exec_tree(t_ast **tree, t_shell *shell);
void	exec_branch(t_ast *branch, t_shell *shell);
void	exec_cmd(t_exec *data, char *bin_path, char **env_cpy);
void	exec_real(t_exec *data, char **env_cpy);
void	exec_clear_data(t_exec *data);
void	exec_slash_access(t_exec *data, char **bin_path);
void	exec_fork_builtin(t_shell *shell, t_exec *data, char **env_cpy);
void	change_in_and_out(t_exec *data);
void	close_fds(int fd_in, int fd_out);

typedef enum e_pipe_fd
{
	PIPE_READ,
	PIPE_WRITE,
	PIPE_IN,
	PIPE_FIRST,
	PIPE_LAST,
}			t_pipe_fd;

#endif
