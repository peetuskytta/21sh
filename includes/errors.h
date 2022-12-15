/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:24:46 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/15 15:05:50 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ERRORS_H
# define ERRORS_H

/*Error message defines*/
# define CMD_TOO_LONG "command line argument is too long"
# define MALLOC_FAIL "malloc failed: serious memory issues"
# define ARG_REQUIRED ": filename argument required"
# define ARG_USAGE_1 ": usage: "
# define ARG_USAGE_2 " filename [arguments]"
# define NO_FILE_OR_DIR ": No such file or directory"
# define HIST_ERR_FILE "Could not open history file."
# define ABORTED_ERROR "Process aborted."
# define ERROR_EXIT "Exit error."
# define NO_STRING ""

/*Error message defines for CD*/
# define CD_NO_HOME " HOME not set"
# define CD_NO_ACCESS " permission denied"
# define CD_NOT_DIR ": Not a directory"
# define CD_SH "shell: cd: "
# define IS_A_DIR ": Is a directory"

/*Error message defines for setenv and unsetenv*/
# define EMPTY_STR "setenv name: cannot be an empty string"
# define NAME_ERROR "setenv name: cannot be a NULL pointer or 0 length string"
# define INVALID_CHAR "setenv name: cannot contain a '=' character"
# define SET_TOO_MANY_ARG "setenv: too many arguments"
# define SETENV_USAGE "usage: 'setenv [name] [value]'"
# define NOT_IDENTIFIER ": not a valid identifier"
# define UNSETENV_USAGE "usage: unsetenv [name]"
# define UNSETENV_ARGS "unsetenv: too many arguments"
# define UNSETENV_TOO_LONG "unsetenv: argument too long"

/*Error messages for fork, waitpid, and execve*/
# define CMD_NOT_FOUND ": command not found"
# define EXEC_NO_ACCESS ": permission denied"
# define EXECVE_ERROR "shell: error with execve"
# define FORK_FAIL "shell: fork fail"
# define WAITPID_FAIL "shell: waitpid fail"
# define EXECVE_ERR "shell: execve error"

/*Error messages for pipe, redirections & tokens*/
# define REDIR_ERR "shell: redirection error"
# define PIPE_ERR "shell: pipe error"
# define BAD_FD "shell: Bad file descriptor:"
# define SYNTAX_ERR "shell: syntax error near unexpected token"

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

# endif
