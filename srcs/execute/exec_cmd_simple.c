// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   exec_cmd_simple.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/02 10:18:29 by pskytta           #+#    #+#             */
// /*   Updated: 2023/01/05 15:27:11 by pskytta          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/execute.h"

// static void	execute_cmd(t_exec data, char *bin_path, char **env_cpy)
// {
// 	t_pid	pid;

// 	pid.child = fork();

// 	if (pid.child == 0)
// 	{
// 		if (execve(bin_path, data.args, env_cpy) == -1)
// 		{
// 			ft_perror(EXECVE_ERROR);
// 			exit(EXIT_FAILURE);
// 		}
// 		exit(EXIT_SUCCESS);
// 	}
// 	else if (pid.child < 0)
// 		ft_perror(FORK_FAIL);
// 	else
// 	{
// 		pid.wait = waitpid(pid.child, &pid.status, 0);
// 		if (pid.wait == -1)
// 			ft_perror(WAITPID_FAIL);
// 	}
// }

// // if no binary found set ERRNO and STDERR "no command found"
// // builtin OR binary (maybe function pointers?)
// void	exec_cmd_simple(t_exec data, char **env_cpy)
// {
// 	char *bin_path;

// 	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data.cmd);
// 	if (exec_binary_check(bin_path, data.cmd))
// 		execute_cmd(data, bin_path, env_cpy);
// 	exec_clear_data(&data, bin_path);
// }
