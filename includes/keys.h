/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 12:26:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# include "shell.h"
# include "structs.h"
/*
** mac key codes
** # define ARW_UP {27, 91, 65}
** # define ARW_DOWN {27, 91, 66}
** # define ARW_RIGHT {27, 91, 67}
** # define ARW_LEFT {27, 91, 68}
** # define END 188
** # define HOME 190
** # define DEL 295
** # define OPTN_UP {27, 91, 49, 59, 51, 65}
** # define OPTN_DOWN {27, 91, 49, 59, 51, 66}
** # define OPTN_RIGHT {27, 102}
** # define OPTN_LEFT {27, 98}
*/
# define CTRL_C 3
# define CTRL_D 4
# define CTRL_P 16
# define CTRL_V 22
# define CTRL_W 23
# define ENTER 13
# define ESC '\x1B'
# define BACK "\x7f"
# define ARW_UP "\x1B[A"
# define ARW_DOWN "\x1B[B"
# define ARW_RIGHT "\x1B[C"
# define ARW_LEFT "\x1B[D"
# define END "\x1B[F"
# define HOME "\x1B[H"
# define DEL "\x1B[3~"
# define OPTN_UP "\x1[1;3A"
# define OPTN_DOWN "\x1[1;3B"
# define OPTN_RIGHT "\x1f"
# define OPTN_LEFT "\x1b"
/*
** KEYS
*/
void	key_listen(t_shell *shell, char *input);
void	read_key(t_shell *shell, char *input);
int		special_keys(t_shell *shell, char *input, int *i);
int		key_is_ctrl_alpha(t_shell *shell, t_win *window, char *input, int *i);
int		key_is_arrow(t_shell *shell, t_win *window, char *input, int *i);

#endif
