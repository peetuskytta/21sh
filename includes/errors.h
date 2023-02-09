/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:24:46 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/07 09:35:55 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*Error message defines*/
# define CMD_TOO_LONG "command line argument is too long\n"
# define QUOTE_TOO_LONG "too many lines. Quote level cannot exceed 4096 lines\n"
# define MALLOC_FAIL "malloc failed: serious memory issues\n"
# define ARG_REQUIRED ": filename argument required\n"
# define ARG_USAGE_1 ": usage: "
# define ARG_USAGE_2 " filename [arguments]\n"
# define NO_FILE_OR_DIR ": no such file or directory\n"
# define HIST_ERR_FILE "Could not open history file.\n"
# define ABORTED_ERROR "Process aborted.\n"
# define ERROR_EXIT "Exit error.\n"
# define NO_STRING ""
# define STDOUT_FAIL "Fail to fetch the stdout. Terminating.\n"
# define STDIN_FAIL "Fail to fetch the stdin. Terminating.\n"
# define STDERR_FAIL "Fail to fetch the stderr. Terminating.\n"
# define EMPTY_ENV "Running 21sh witth empty environment not allowed. \
Terminating all processes.\n"

/*Error message defines for CD*/
# define CD_NO_HOME "cd: HOME not set\n"
# define CD_NO_OLDPWD "cd: OLDPWD not set\n"
# define CD_NO_ACCESS ": permission denied\n"
# define CD_NOT_DIR ": Not a directory\n"
# define CD_NO_FILE_OR_DIR "no such file or directory\n"
# define CD_SH "21sh: cd: "
# define IS_A_DIR ": Is a directory\n"
# define CD_ARG_NO "cd: too many arguments\n"

/*Error message defines for setenv and unsetenv*/
# define EMPTY_STR "setenv name: cannot be an empty string\n"
# define NAME_ERROR "setenv name: cannot be a NULL pointer or 0 length string\n"
# define INVALID_CHAR "setenv name: must begin with Alpha cahracter\n"
# define SET_TOO_MANY_ARG "env/setenv: too many arguments\n"
# define SETENV_USAGE "usage: 'setenv [name]=[value]'\n"
# define NOT_IDENTIFIER ": not a valid identifier\n"
# define UNSETENV_USAGE "usage: unsetenv [name]\n"
# define UNSETENV_ARGS "unsetenv: too many arguments\n"
# define UNSETENV_TOO_LONG "unsetenv: argument too long\n"

/*Error message defines for env*/
# define ENV_USE "env: usage: env OR env -i {name=value}\n"

/*Error messages for fork, waitpid, and execve*/
# define CMD_NOT_FOUND ": command not found\n"
# define EXEC_NO_ACCESS ": permission denied\n"
# define EXECVE_ERROR "21sh: error with execve\n"
# define FORK_FAIL "21sh: fork fail\n"
# define WAITPID_FAIL "21sh: waitpid fail\n"
# define EXECVE_ERR "21sh: execve error\n"
# define TCGET_ERR "Error with tcgetattr\n"
# define TTY_TERM_ERR "ttyname() failed to retrieve terminal name.\n"

/*Error messages for pipe, redirections & tokens*/
# define REDIR_ERR "21sh: redirection error\n"
# define PIPE_ERR "21sh: pipe error\n"
# define BAD_FD "21sh: Bad file descriptor: "
# define SYNTAX_ERR "21sh: syntax error near unexpected token\n"
# define SYNTAX_ERR_NL "syntax error near unexpected token `newline'\n"
# define PARSE_ERR "21sh: parse error near "
# define AGGR_ERR "21sh: redir and closing file descriptor not allowed\n"
# define GEN_ARG "21sh: too many pipes or semicolons\n"
# define MANY_ARG "21sh: too many arguments or redirections\n"

/*Error messages for file descriptors*/
# define HEREDOC_EXIST "heredoc: already exists. Delete file and try again.\n"
# define FILE_CLOSE_ERR "21sh: error when closing a file\n"
# define FILE_OPEN_ERR "21sh: error when opening a file\n"

# define MALLOC_ERRNO		2
# define FORK_ERRNO			3
# define EXECVE_ERRNO		4
# define SYNTAX_ERRNO		5
# define PERMISSION_ERRNO 	6
# define NOT_FOUND_ERRNO	7
# define NOT_DIR_ERRNO		8
# define PIPE_ERRNO			9
# define REDIR_ERRNO		10
# define BAD_FD_ERRNO		11
# define ABORT_ERRNO		12
# define ENV_NAME_ERRNO		13
# define ENV_INVALID_ERRNO	14
# define SYSTEM_CALL_FAIL	15

#endif
