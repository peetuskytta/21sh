/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:40:33 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 10:55:25 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAWMODE_H
# define RAWMODE_H
# include "shell.h"
# include "structs.h"

/*
** RAW
*/
int		enable_rawmode(t_shell *shell);
void	kill_mode(const char *str, t_shell *shell);

#endif
