/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 13:25:39 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef KEYS_H
# define KEYS_H
# include "shell.h"
# include "structs.h"
/*
** mac key codes
*/
# define CTRL_C 3
# define CTRL_D 4
# define ENTER 13
# define ESC 27
# define SPACE 32
# define BACK 127
# define ARW_UP {27, 91, 65}
# define ARW_DOWN {27, 91, 66}
# define ARW_RIGHT {27, 91, 67}
# define ARW_LEFT {27, 91, 68}
# define END 188
# define HOME 190
# define DEL 295
# define OPTN_UP {27, 91, 49, 59, 51, 65}
# define OPTN_DOWN {27, 91, 49, 59, 51, 66}
# define OPTN_RIGHT {27, 102}
# define OPTN_LEFT {27, 98}

/*
** KEYS
*/
int		ft_iscntrl(char c);
void	keypress(t_shell *shell, char *read_str);
void	read_key(t_shell *shell, char *input);
int		special_keys(t_shell *shell, char *input);

#endif
