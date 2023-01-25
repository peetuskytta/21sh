/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:59:10 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 16:50:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** The abort() first unblocks the SIGABRT signal, and then raises that signal 
** for the calling process. This results in the abnormal termination of the 
** process unless the SIGABRT signal is caught and the signal handler does not
** return 
** 	sigabrt process handling after PERROR!
*/

void	ft_abort(void)
{
	ft_perror(ABORTED_ERROR);
	exit(EXIT_FAILURE);
}
